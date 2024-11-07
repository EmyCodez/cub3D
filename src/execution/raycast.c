/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:03:38 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/07 13:51:33 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	color_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->address + (y * image->line_length + x * (image->bits_pixel
				/ 8));
	*(unsigned int *)dst = color;
}
void	paint_line(t_image *image, t_line *line, int color)
{
	int	y;

	y = line->y_start;
	if (y >= 0)
	{
		while (y < line->y_end)
		{
			color_pixel(image, line->x, y, color);
			y++;
		}
	}
}

static void	set_wall_height(t_line *line, double wall_dist)
{
	line->wall_height = (int)(WIN_HEIGHT / wall_dist);
	line->wall_start = (-line->wall_height / 2) + (WIN_HEIGHT / 2);
	if (line->wall_start < 0)
		line->wall_start = 0;
	line->wall_end = (line->wall_height / 2) + (WIN_HEIGHT / 2);
	if (line->wall_end >= WIN_HEIGHT)
		line->wall_end = WIN_HEIGHT - 1;
}

static void	draw_wall(t_data *data, int current_x)
{
	double	wall_x;

	if (data->ray.next_hop == 0)
		wall_x = data->player.pos_y + data->ray.wall_dist * data->ray.raydir_y;
	else
		wall_x = data->player.pos_x + data->ray.wall_dist * data->ray.raydir_x;
	wall_x -= floor(wall_x);
	data->line.x = current_x;
	set_wall_height(&data->line, data->ray.wall_dist);
	if (data->map.map_data[data->ray.map_x][data->ray.map_y] == '1')
	{
		data->line.y_start = data->line.wall_start;
		data->line.y_end = data->line.wall_end;
	}
	data->line.y_start = 0;
	data->line.y_end = data->line.wall_start;
	paint_line(&data->win_img, &data->line, data->ceiling_color);
	data->line.y_start = data->line.wall_end;
	data->line.y_end = WIN_HEIGHT;
	paint_line(&data->win_img, &data->line, data->floor_color);
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
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->win_img.img, 0,
			0);
}