/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:37:48 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/30 08:55:16 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bresenhem_p2(t_mapinfo *map, t_bresenhem *a)
{
	int	i;

	if (a->dy > a->dx)
	{
		i = 1;
		init_bresenh2(a);
		mlx_pixel_put(map->mlx, map->win, a->x0 + WIDTH / 2,
			a->y0 + HEIGHT / 2, 0xFFFFFF);
		while (i <= a->dy)
		{
			if (a->d > 0)
			{
				a->d += a->d2;
				a->x += a->sx;
			}
			else
				a->d += a->d1;
			mlx_pixel_put(map->mlx, map->win, a->x + WIDTH / 2,
				a->y + HEIGHT / 2, 0xFFFFFF);
			i++;
			a->y += a->sy;
		}
	}
}

void	bresenhem_p1(t_mapinfo *map, t_bresenhem *a)
{
	int	i;

	if (a->dy <= a->dx)
	{
		i = 1;
		init_bresenh1(a);
		mlx_pixel_put(map->mlx, map->win, a->x0 + WIDTH / 2,
			a->y0 + HEIGHT / 2, 0xFFFFFF);
		while (i <= a->dx)
		{
			if (a->d > 0)
			{
				a->d += a->d2;
				a->y += a->sy;
			}
			else
				a->d += a->d1;
			mlx_pixel_put(map->mlx, map->win, a->x + WIDTH / 2,
				a->y + HEIGHT / 2, 0xFFFFFF);
			i++;
			a->x += a->sx;
		}
	}
}

void	draw_line(t_mapinfo *map, t_vec vec1, t_vec vec2)
{
	t_bresenhem		a;
	int				x1;
	int				y1;

	a.x0 = (int)vec1.x;
	a.y0 = (int)vec1.y;
	x1 = (int)vec2.x;
	y1 = (int)vec2.y;
	a.dx = abs(x1 - a.x0);
	a.dy = abs(y1 - a.y0);
	a.sx = x1 >= a.x0 ? 1 : -1;
	a.sy = y1 >= a.y0 ? 1 : -1;
	bresenhem_p1(map, &a);
	bresenhem_p2(map, &a);
}
