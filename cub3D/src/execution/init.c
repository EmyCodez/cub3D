/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:38:37 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/03 15:38:52 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	find_player_position(char **map, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player->pos_x = i;
				player->pos_y = j;
				player->direction = map[i][j];
				return ;
			}
		}
	}
}

static void	init_keys(t_key *keys)
{
	keys->press_w = false;
	keys->press_s = false;
	keys->press_a = false;
	keys->press_d = false;
	keys->press_left = false;
	keys->press_right = false;
}

static void	init_player(t_data *data)
{
	find_player_position(data->map.map_data, &data->player);
	printf("\n Player Position: x= %f, y=%f \n Player direction: %c",
			data->player.pos_x,
			data->player.pos_y,
			data->player.direction);
	set_player_direction(&data->player);
	data->player.cam_height = WIN_HEIGHT / 8;
}

void	init(t_data *data)
{
	init_keys(&data->key);
	init_player(data);
	data->floor_color = 0;
	data->ceiling_color = 24;
}