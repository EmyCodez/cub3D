/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:10:52 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/10 13:52:42 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		printf(RED"(ERROR) Input 2 arguments\n"RESET);
		exit(EXIT_FAILURE);
	}
	parse_input(av[1], &map);
	return (0);
}
