

#include "../../includes/cub3D.h"

int	read_map(t_map *map)
{
	map->rows = 24;
	map->cols = 24;
	map->map_data = ft_calloc(24, sizeof(char *));
	map->map_data[0] = ft_strdup("111111111111111111111111");
	map->map_data[1] = ft_strdup("100000000000000000000001");
	map->map_data[2] = ft_strdup("100000000000000000000001");
	map->map_data[3] = ft_strdup("100000000000000000000001");
	map->map_data[4] = ft_strdup("100000222220000303030001");
	map->map_data[5] = ft_strdup("100000200020000000000001");
	map->map_data[6] = ft_strdup("100000200020000300030001");
	map->map_data[7] = ft_strdup("100000200020000000000001");
	map->map_data[8] = ft_strdup("100000220220000303030001");
	map->map_data[9] = ft_strdup("100000000000000000000001");
	map->map_data[10] = ft_strdup("100000000000000000000001");
	map->map_data[11] = ft_strdup("100000000000000000000001");
	map->map_data[12] = ft_strdup("100000000000000000000001");
	map->map_data[13] = ft_strdup("100000000000000000000001");
	map->map_data[14] = ft_strdup("100000000000000000000001");
	map->map_data[15] = ft_strdup("100000000000000000000001");
	map->map_data[16] = ft_strdup("144444444000000000000001");
	map->map_data[17] = ft_strdup("140400004000000000000001");
	map->map_data[18] = ft_strdup("140000504000000000000001");
	map->map_data[19] = ft_strdup("140400004000000000000001");
	map->map_data[20] = ft_strdup("140444444000000000000001");
	map->map_data[21] = ft_strdup("140000000000000000000001");
	map->map_data[22] = ft_strdup("144444444000S00000000001");
	map->map_data[23] = ft_strdup("111111111111111111111111");
	return (0);
}

int	dummy_parse(int argc, char **argv, t_data *dt)
{
	printf("\n argc= %d argv=%s", argc, argv[1]);
	read_map(&dt->map);
	return (0);
}
