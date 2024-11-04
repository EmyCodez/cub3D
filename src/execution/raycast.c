/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:38 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/04 16:05:51 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_wall(t_data *data, int x)
{
	double	wall_x;

	if (data->ray.next_hop == 0)
		wall_x = data->player.pos_y + data->ray.wall_dist * data->ray.raydir_y;
	else
		wall_x = data->player.pos_x + data->ray.wall_dist * data->ray.raydir_x;
	wall_x -= floor(wall_x);
}

void	raycast(t_data *data)
{
	int x;
	x = -1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (++x < WIN_WIDTH)
	{
		data->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		data->ray.raydir_x = data->player.dir_x + data->player.plane_x
			* data->player.camera_x;
		data->ray.raydir_y = data->player.dir_y + data->player.plane_y
			* data->player.camera_x;
		set_ray_length(&data->ray, &data->player);
		calculate_wall_distance(&data->map, &data->ray, &data->player);
		draw_wall(data, x);
		// mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->ray.raydir_x
		// 		+ data->ray.dx, data->ray.raydir_y + data->ray.dy,
		// 		data->ceiling_color);
		// mlx_loop(data->mlx_ptr);
	}
}