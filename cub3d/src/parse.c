/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:25:09 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/20 18:21:21 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_input(char **av, t_map *map)
{
	if (!validate_file_extention(av[1]))
		exit(EXIT_FAILURE);
	if (!validate_texture(av, map))
		exit(EXIT_FAILURE);
	struct_initialization(map);
}