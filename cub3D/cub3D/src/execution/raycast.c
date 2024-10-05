/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:00:19 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/05 15:32:01 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_line_height(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	color_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	paint_line(t_data *root, t_line *line, int rgb)
{
	int	y;
	int	y_max;

	y = line->y0;
	y_max = line->y1;
	if (y >= 0)
	{
		while (y < y_max)
		{
			color_pixel(&root->image, line->x, y, rgb);
			y++;
		}
	}
}

void	draw_wall(t_data *root, t_ray *ray, int current_x)
{
	t_line	line;
	double	wall_x;

	root->ceiling_color = 6591981;
	root->floor_color = 8421504;
	if (ray->side == 0)
		wall_x = root->player.pos_y + ray->wall_dist * ray->raydir_y;
	else
		wall_x = root->player.pos_x + ray->wall_dist * ray->raydir_x;
	wall_x -= floor(wall_x);
	line.x = current_x;
	get_line_height(ray);
	if (root->map.map_data[ray->map_x][ray->map_y] == '1')
	{
		line.y0 = ray->draw_start;
		line.y1 = ray->draw_end;
		//	paint_texture_line(root, ray, &line, wall_x);
	}
	line.y0 = 0;
	line.y1 = ray->draw_start;
	paint_line(root, &line, root->ceiling_color);
	line.y0 = ray->draw_end;
	line.y1 = WIN_HEIGHT;
	paint_line(root, &line, root->floor_color);
}

void	raycast(t_data *dt)
{
	int x = -1;
	mlx_clear_window(dt->mlx_ptr, dt->win_ptr);
	while (++x < WIN_WIDTH)
	{
		dt->player.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		dt->ray.raydir_x = dt->player.dir_x + dt->player.plane_x
			* dt->player.camera_x;
		dt->ray.raydir_y = dt->player.dir_y + dt->player.plane_y
			* dt->player.camera_x;
		set_ray_length(&dt->ray, &dt->player);
		calculate(&dt->ray, &dt->map, &dt->player);
		draw_wall(dt, &dt->ray, x);
	}
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->image.img, 0, 0);
}