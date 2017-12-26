#include "header.h"

void	transform(t_mapinfo *map)
{
	int i;
	int j;

	map->vec = (t_vec *)malloc(sizeof(t_vec) * map->lines * map->values);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->values)
		{
			map->vec[i * map->values + j].x = j;
			map->vec[i * map->values + j].y = i;
			map->vec[i * map->values + j].z = map->numbers[i][j];
			j++;
		}
		i++;
	}
	map->quantity = map->values * map->lines;
}