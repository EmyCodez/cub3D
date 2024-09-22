/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:25:09 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/22 12:38:06 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_input(char *path, t_map *map)
{
	struct_initialization(map);
	if (!validate_file_extention(path))
		exit(EXIT_FAILURE);
	if (!validate_texture(path, map))
		exit(EXIT_FAILURE);
}