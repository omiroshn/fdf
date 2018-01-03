/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:37:48 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/02 20:55:05 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int clerp(int color1, int color2, double percent)
{
	int r;
	int g;
	int b;

	if (color1 == color2)
		return (color1);
	r = ft_lerpi((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, percent);
	g = ft_lerpi((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, percent);
	b = ft_lerpi(color1 & 0xFF, color2 & 0xFF, percent);
	return (r << 16 | g << 8 | b);
}

double	ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return (fabs((val - first) / (second - first)));
}

void	bresenhem_p2(t_mapinfo *map, t_bresenhem *a)
{
	int	i;
	double percent;

	if (a->disty > a->distx)
	{
		i = 1;
		init_bresenh2(a);
		percent = ft_ilerp(a->d1, a->y0, a->y1);
		mlx_pixel_put(map->mlx, map->win, a->x0 + WIDTH / 2,
			a->y0 + HEIGHT / 2, clerp(a->color, a->color2, percent));
		while (i <= a->disty)
		{
			if (a->d > 0)
			{
				a->d += a->d2;
				a->x += a->sx;
			}
			else
				a->d += a->d1;
			mlx_pixel_put(map->mlx, map->win, a->x + WIDTH / 2,
				a->y + HEIGHT / 2, clerp(a->color, a->color2, percent));
			i++;
			a->y += a->sy;
		}
	}
}

void	bresenhem_p1(t_mapinfo *map, t_bresenhem *a)
{
	int	i;
	double percent;

	if (a->disty <= a->distx)
	{
		i = 1;
		init_bresenh1(a);
		percent = ft_ilerp(a->d2, a->x0, a->x1);
		mlx_pixel_put(map->mlx, map->win, a->x0 + WIDTH / 2,
			a->y0 + HEIGHT / 2, clerp(a->color, a->color2, percent));
		while (i <= a->distx)
		{
			if (a->d > 0)
			{
				a->d += a->d2;
				a->y += a->sy;
			}
			else
				a->d += a->d1;
			mlx_pixel_put(map->mlx, map->win, a->x + WIDTH / 2,
				a->y + HEIGHT / 2, clerp(a->color, a->color2, percent));
			i++;
			a->x += a->sx;
		}
	}
}

void	draw_line(t_mapinfo *map, t_vec vec1, t_vec vec2)
{
	t_bresenhem		a;

	a.color = vec1.color;
	a.color2 = vec2.color;
	a.x0 = (int)vec1.x;
	a.y0 = (int)vec1.y;
	a.x1 = (int)vec2.x;
	a.y1 = (int)vec2.y;
	a.distx = abs(a.x1 - a.x0);
	a.disty = abs(a.y1 - a.y0);
	a.sx = a.x1 >= a.x0 ? 1 : -1;
	a.sy = a.y1 >= a.y0 ? 1 : -1;
	bresenhem_p1(map, &a);
	bresenhem_p2(map, &a);
}
