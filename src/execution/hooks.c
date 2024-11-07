/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:08:18 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/07 16:11:20 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	on_keyrelease(int key, void *info)
{
	t_data	*data;

	(void)info;
	data = (t_data *)info;
	if (key == KEY_W)
		data->key.w = false;
	else if (key == KEY_A)
		data->key.a = false;
	else if (key == KEY_D)
		data->key.d = false;
	else if (key == KEY_S)
		data->key.s = false;
	else if (key == KEY_RIGHT)
		data->key.right = false;
	else if (key == KEY_LEFT)
		data->key.left = false;
	return (0);
}
int	hook_loop(void *info)
{
	t_data	*data;

	(void)info;
	data = (t_data *)info;
	if (data->key.w)
		move_forward(data);
	else if (data->key.s)
		move_backward(data);
	else if (data->key.a)
		move_left(data);
	else if (data->key.d)
		move_right(data);
	else if (data->key.left)
		rotate_left(&data->player);
	else if (data->key.right)
		rotate_right(&data->player);
	raycast(data);
	return (0);
}
int	on_keypress(int key, void *info)
{
	t_data	*data;

	(void)info;
	data = (t_data *)info;
	if (key == KEY_ESC)
		exit_game(data);
	else if (key == KEY_W)
		data->key.w = true;
	else if (key == KEY_A)
		data->key.a = true;
	else if (key == KEY_D)
		data->key.d = true;
	else if (key == KEY_S)
		data->key.s = true;
	else if (key == KEY_RIGHT)
		data->key.right = true;
	else if (key == KEY_LEFT)
		data->key.left = true;
	return (0);
}
int	exit_game(void *info)
{
	t_data *data;

	(void)info;
	data = (t_data *)info;
	if (data->win_img.img)
		mlx_destroy_image(data->mlx_ptr, data->win_img.img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//ft_free((void **)&(data->mlx_ptr));
	printf("\nGame exited\n");
	exit(0);
	return (0);
}