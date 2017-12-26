/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:42:15 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/26 21:42:17 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			map->vec[i * map->values + j].x = j + WIDTH / 2 ;
			map->vec[i * map->values + j].y = i + HEIGHT / 2;
			map->vec[i * map->values + j].z = map->numbers[i][j] * 15;
			j++;
		}
		i++;
	}
	map->quantity = map->values * map->lines;
}
