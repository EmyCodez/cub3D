/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:52:28 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/05 15:56:01 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	on_keyrelease(int key, void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (key == W)
		data->keys.w = false;
	else if (key == A)
		data->keys.a = false;
	else if (key == D)
		data->keys.d = false;
	else if (key == S)
		data->keys.s = false;
	else if (key == RIGHT)
		data->keys.right = false;
	else if (key == LEFT)
		data->keys.left = false;
	else if (key == UP)
		data->keys.up = false;
	else if (key == DOWN)
		data->keys.down = false;
	return (0);
}

int	exit_game(void *info)
{
	t_data	*data;

	(void)info;
	data = (t_data *)info;
	free_2d_array(&data->map.map_data);
	free_map_infos(&data->map_infos);
	if (data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	if (data->north_texture.img)
		mlx_destroy_image(data->mlx, data->north_texture.img);
	if (data->south_texture.img)
		mlx_destroy_image(data->mlx, data->south_texture.img);
	if (data->east_texture.img)
		mlx_destroy_image(data->mlx, data->east_texture.img);
	if (data->west_texture.img)
		mlx_destroy_image(data->mlx, data->west_texture.img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	ft_free((void **)&(data->mlx));
	printf("Game exited\n");
	exit(0);
	return (0);
}

int	hook_loop(void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (data->keys.w)
		go_forward(data);
	else if (data->keys.s)
		go_backward(data);
	else if (data->keys.a)
		move_left(data);
	else if (data->keys.d)
		move_right(data);
	else if (data->keys.left)
		rotate_left(data);
	else if (data->keys.right)
		rotate_right(data);
	else if (data->keys.up)
		go_forward(data);
	else if (data->keys.down)
		go_backward(data);
	cast_rays(data, &data->player);
	return (0);
}

int	on_keypress(int key, void *info)
{
	t_data	*data;

	data = (t_data *)info;
	if (key == ESC)
		exit_game(data);
	else if (key == W)
		data->keys.w = true;
	else if (key == A)
		data->keys.a = true;
	else if (key == D)
		data->keys.d = true;
	else if (key == S)
		data->keys.s = true;
	else if (key == RIGHT)
		data->keys.right = true;
	else if (key == LEFT)
		data->keys.left = true;
	else if (key == UP)
		data->keys.up = true;
	else if (key == DOWN)
		data->keys.down = true;
	return (0);
}
