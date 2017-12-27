/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:42:15 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/27 18:01:27 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	transform(t_mapinfo *map)
{
	int i;
	int j;

	map->vec = (t_vec *)malloc(sizeof(t_vec) * map->lines * map->values);
	lenth_of_z(map);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->values)
		{
			map->vec[i * map->values + j].x = j - map->values / 2;
			map->vec[i * map->values + j].y = i - map->lines / 2;
			map->vec[i * map->values + j].z = map->numbers[i][j] - (map->max_len_z - map->min_len_z) / 2;
			map->vec[i * map->values + j].w = 1;
			j++;
		}
		i++;
	}
	map->quantity = map->values * map->lines;
}

void lenth_of_z(t_mapinfo *map)
{
	int i;
	int j;

	i = 0;
	map->max_len_z = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->values)
		{
			if (map->numbers[i][j] > map->max_len_z)
				map->max_len_z = map->numbers[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	map->min_len_z = map->numbers[0][0];
	while (i < map->lines)
	{
		j = 0;
		while (j < map->values)
		{
			if (map->min_len_z < map->numbers[i][j])
				map->min_len_z = map->numbers[i][j];
			j++;
		}
		i++;
	}
}
