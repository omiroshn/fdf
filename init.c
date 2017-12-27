/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:41:35 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/27 19:11:04 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init(t_mapinfo *map)
{
	//init_center(map);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "omiroshn's fdf");
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->lines = 0;
	map->values = 0;
	map->scale = 15;
}

void	init_center(t_mapinfo *map)
{
	int			i;

	i = 0;
	while (i < map->quantity)
	{
		map->vec[i].x += HEIGHT / 60;
		map->vec[i].y += WIDTH / 60;
		i++;
	}
}

int exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
