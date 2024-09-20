#include "../includes/cub3d.h"

t_map	*dummy_init(void) // init the map structure
{
	t_map *map = calloc(1, sizeof(t_map));
	// init the map structure
	map->arr_map = calloc(10, sizeof(char *));                // init the map
	map->arr_map[0] = ft_strdup("1111111111111111111111111"); //fill the map
	map->arr_map[1] = ft_strdup("1000000000000000000100001");
	map->arr_map[2] = ft_strdup("1001000000000P00000000001");
	map->arr_map[3] = ft_strdup("1001000000000000001000001");
	map->arr_map[4] = ft_strdup("1001000000000000001000001");
	map->arr_map[5] = ft_strdup("1001000000100000001000001");
	map->arr_map[6] = ft_strdup("1001000000000000001000001");
	map->arr_map[7] = ft_strdup("1001000000001000001000001");
	map->arr_map[8] = ft_strdup("1111111111111111111111111");
	map->arr_map[9] = NULL;
	map->player_y = 3;  // player y position in the map
	map->player_x = 14; // player x position in the map
	map->width = 25;    // map width
	map->height = 9;    // map height
	return (map);       // return the map structure
}
