/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:07:29 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/03 14:20:57 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_valid_characters(t_map *map)
{
	int		i;
	int		j;
	char	*allowed_chars;

	i = 0;
	allowed_chars = "01 NSEW";
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (!ft_strchr(allowed_chars, map->map_data[i][j]))
				return (ft_printf(RED "Error\n" RESET "Invalid character '%c' in map\n", map->map_data[i][j]), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_player_position(t_map *map)
{
    int i = 0;
    int j;
    int player_count = 0;

    while (map->map_data[i])
    {
        j = 0;
        while (map->map_data[i][j])
        {
            if (ft_strchr("NSEW", map->map_data[i][j]))
                player_count++;
            j++;
        }
        i++;
    }
    if (player_count != 1)
        return (ft_printf(RED "Error\n" RESET "There should be exactly 1 player start position, found %d\n", player_count), 0);
    return (1);
}

int check_walls(t_map *map)
{
    int i = 0;
    int j;

    // Check top and bottom rows (should only contain '1' and spaces)
    while (map->map_data[0][i] && map->map_data[map->map_height - 1][i])
    {
        if (map->map_data[0][i] != '1' && map->map_data[0][i] != ' ')
            return (ft_printf(RED "Error\n" RESET "Top boundary is not closed by walls\n"), 0);
        if (map->map_data[map->map_height - 1][i] != '1' && map->map_data[map->map_height - 1][i] != ' ')
            return (ft_printf(RED "Error\n" RESET "Bottom boundary is not closed by walls\n"), 0);
        i++;
    }

    // Check left and right sides
    i = 0;
    while (map->map_data[i])
    {
        if (map->map_data[i][0] != '1' && map->map_data[i][0] != ' ')
            return (ft_printf(RED "Error\n" RESET "Left boundary is not closed by walls\n"), 0);
        j = ft_strlen(map->map_data[i]) - 1;
        if (map->map_data[i][j] != '1' && map->map_data[i][j] != ' ')
            return (ft_printf(RED "Error\n" RESET "Right boundary is not closed by walls\n"), 0);
        i++;
    }
    return (1);
}



int	map_checks(t_map *map)
{
    if (!check_valid_characters(map))
        return (0);
	ft_printf(GREEN"Character check Successfull\n"RESET);
    if (!check_player_position(map))
        return (0);
	ft_printf(GREEN"Player Position Check Successfull\n"RESET);
	if (!check_walls(map))
		return (0);
	if (!validate_and_replace_spaces(map))
		return (0);
    ft_printf(GREEN"Map Wall Check Successfull\n"RESET);
	return (1);
}