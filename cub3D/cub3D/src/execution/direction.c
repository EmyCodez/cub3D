/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:24:07 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/03 15:40:21 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_player_direction(t_player *player)
{
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
	// if (dir == 'E')
	// {
	// 	set_direction_east(data);
	// }
	// else if (dir == 'W')
	// {
	// 	set_direction_west(data);
	// }
	// else if (dir == 'N')
	// {
	// 	set_direction_north(data);
}