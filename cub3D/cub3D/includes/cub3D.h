/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:55:00 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/05 15:51:37 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../library/libft/libft.h"
# include "../library/mlx/mlx.h"
# include "keys.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 720
# define WIN_HEIGHT 560
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.05

/* struct to handle rgb colors */
typedef struct s_color
{
	long		r;
	long		g;
	long		b;
}				t_color;

typedef struct s_line
{
	int			x;
	int			y;
	int			y0;
	int			y1;
}				t_line;

typedef struct s_map
{
	int			cols;
	int			rows;
	char		**map_data;
}				t_map;

typedef struct s_map_info
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_color		floor_color;
	t_color		ceiling_color;
}				t_map_info;

/* struct to handle image attributes */
typedef struct s_image
{
	int			height;
	int			width;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_image;

/* struct to check when keys are pressed */
typedef struct s_key
{
	bool		press_w;
	bool		press_s;
	bool		press_a;
	bool		press_d;
	bool		press_left;
	bool		press_right;
}				t_key;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		delta_x;
	double		delta_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			side;
	double		wall_dist;
	int			current_x;
	int			draw_start;
	int			line_height;
	int			draw_end;
}				t_ray;

typedef struct s_player
{
	double		cam_height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	double		camera_x;
	char		direction;
	t_line		line;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	t_ray		ray;
	t_key		key;
	t_map		map;
	t_map_info	mp_info;
	t_player	player;
	t_image		north_texture;
	t_image		south_texture;
	t_image		west_texture;
	t_image		east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_data;

// FUNCTIONS
int				dummy_parse(int argc, char **argv, t_data *dt);
void			init(t_data *data);
void			set_player_direction(t_player *player);
void			set_ray_length(t_ray *ray, t_player *player);
void			calculate(t_ray *ray, t_map *map, t_player *player);
void			raycast(t_data *dt);
void			execute(t_data *data);

#endif