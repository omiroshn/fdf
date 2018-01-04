/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:37:48 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 17:36:27 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int		clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

double	ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

void	line_process(t_mapinfo *map, t_bresenhem *a, t_vec *vec1, t_vec *vec2)
{
	double percent;

	percent = (a->distx > a->disty ?
			ft_ilerp(a->x0, a->start.x, a->stop.x)
			: ft_ilerp(a->y0, a->start.y, a->start.y));
	mlx_pixel_put(map->mlx, map->win, a->x0 + WIDTH / 2,
			a->y0 + HEIGHT / 2, clerp(vec1->color, vec2->color, percent));
	a->err2 = 2 * a->err;
	if (a->err2 >= a->disty)
	{
		a->err += a->disty;
		a->x0 += a->sx;
	}
	else if (a->err2 <= a->distx)
	{
		a->err += a->distx;
		a->y0 += a->sy;
	}
}

void	draw_line(t_mapinfo *map, t_vec vec1, t_vec vec2)
{
	t_bresenhem		a;

	a.x0 = (int)vec1.x;
	a.y0 = (int)vec1.y;
	a.x1 = (int)vec2.x;
	a.y1 = (int)vec2.y;
	a.start = vec1;
	a.stop = vec2;
	a.distx = abs(a.x1 - a.x0);
	a.disty = -abs(a.y1 - a.y0);
	a.sx = a.x0 < a.x1 ? 1 : -1;
	a.sy = a.y0 < a.y1 ? 1 : -1;
	a.err = a.distx + a.disty;
	while (a.x0 != a.x1 || a.y0 != a.y1)
		line_process(map, &a, &vec1, &vec2);
}
