/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:08:07 by esimpson          #+#    #+#             */
/*   Updated: 2024/09/19 15:46:09 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1000
# define TILE_SIZE 30
# define FOV 60

// Libraries
# include "../library/libft/libft.h"
# include "../library/mlx/mlx.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	char	**arr_map;

}			t_map;

typedef struct s_ray
{
	double	distance;
	double	ray_angle;
	int		wall_flag;
}			t_ray;

typedef struct s_image
{
	void	*image;
}			t_image;

// FUNCTIONS
t_map		*dummy_init(void);

#endif