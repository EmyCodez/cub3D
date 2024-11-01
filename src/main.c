/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:10:52 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/01 15:51:42 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
	{
		printf(RED "(ERROR) Input 2 arguments\n" RESET);
		exit(EXIT_FAILURE);
	}
	parse_input(av[1], &data.map);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data.cur_img.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.cur_img.address = mlx_get_data_addr(data.cur_img.img,
												&data.cur_img.bits_pixel,
												&data.cur_img.line_length,
												&data.cur_img.endian);
	execute(&data);
	printf("\n Player Position: X= %f Y=%f ", data.player.pos_x,
			data.player.pos_y);
	printf("\n Player Direction: %c", data.player.direction);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, (int)data.player.dir_x,
			(int)data.player.dir_y, data.ceiling_color);
	mlx_loop(data.mlx_ptr);
	return (0);
}
