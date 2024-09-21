/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:08:07 by esimpson          #+#    #+#             */
/*   Updated: 2024/09/20 18:23:03 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1000
# define TILE_SIZE 30
# define FOV 60

/* ------------------------------- INCLUDES --------------------------------- */

# include "../library/libft/libft.h"
# include "../library/get_next_line/get_next_line.h"
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

# define COLOUR_EXCEED_VALUE 255

/* ----------------------------- DATA STRUCTURES --------------------------- */

typedef struct t_list
{
	char	**map;
	int		f_red;
	int		f_green;
	int		f_blue;
	int		c_red;
	int		c_green;
	int		c_blue;
	char	no_texture_path;
	char	so_texture_path;
	char	ea_texture_path;
	char	we_texture_path;
}	t_map;

/* --------------------------- FUNCTION PROTOTYPES ------------------------- */

/* ************************************************************************** */
/*                              FILENAME: parse.c                             */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

void	parse_input(char **av, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: struct_init.c                       */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

void	struct_initialization(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: extention_check.c                   */
/* USAGE:                                                                     */
/* Include this header file in any C file that requires access to the         */
/* [module] functions and data types. Example:                                */
/* ************************************************************************** */

int	validate_file_extention(char *str);

#endif