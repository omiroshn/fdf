/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:41:35 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/03 23:04:34 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init(t_mapinfo *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "omiroshn's fdf");
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->lines = 0;
	map->values = 0;
	map->scale = 1;
	map->offset_x = 0;
	map->offset_y = 0;
	map->offset_z = 1;
	map->speed = 10;
	map->turned_on = 1;
}

void	init_perspective_projection(t_persp_proj *proj)
{
	proj->n = 0.01;
	proj->f = 100;
	proj->angle_of_view = 60;
	proj->image_aspect_ratio = HEIGHT / WIDTH;
	proj->scale = tan(proj->angle_of_view * 0.5 * M_PI / 180) * proj->n;
	proj->b = proj->t * -1;
	proj->t = proj->scale;
	proj->r = proj->image_aspect_ratio * proj->scale;
	proj->l = proj->r * -1;
}

int		exit_func(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}
