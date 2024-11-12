/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:48:34 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/12 15:49:31 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_line(char *line)
{
	while (*line == ' ')
		line++;
	return (*line == '1' || *line == '0');
}

void	free_map_data(t_map *map, int line_count)
{
	int	i;

	i = 0;
	while (i < line_count)
	{
		free(map->map_data[i]);
		i++;
	}
}
