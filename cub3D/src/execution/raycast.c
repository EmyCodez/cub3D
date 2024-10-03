/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:00:19 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/03 16:02:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_ray_length(t_ray *ray, t_player *player)
{
	//which box of the map we're in
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	//delta_x and delta_y length of ray from one x or y-side to next x or y
	if (ray->raydir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->raydir_y);
}

void	get_line_height(t_ray *ray)
{
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
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
	}
}