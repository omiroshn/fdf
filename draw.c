/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:41:23 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 01:36:55 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_last_line(t_mapinfo *map, int i)
{
	int	j;

	j = 0;
	while (j < map->values - 1)
	{
		draw_line(map, map->vec_ch[i * map->values + j],
			map->vec_ch[i * map->values + j + 1]);
		j++;
	}
}

void	draw_all_lines(t_mapinfo *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines - 1)
	{
		j = 0;
		draw_line(map, map->vec_ch[i * map->values + j],
			map->vec_ch[i * map->values + j + map->values]);
		j++;
		while (j < map->values)
		{
			draw_line(map, map->vec_ch[i * map->values + j],
				map->vec_ch[i * map->values + j - 1]);
			draw_line(map, map->vec_ch[i * map->values + j],
				map->vec_ch[i * map->values + j + map->values]);
			j++;
		}
		i++;
	}
	draw_last_line(map, i);
}

void	draw(t_mapinfo *map)
{
	int			i;
	t_matrix4	m_rot[7];

	m_rot[0] = rotate_vectors_x(map);
	m_rot[1] = rotate_vectors_y(map);
	m_rot[2] = rotate_vectors_z(map);
	m_rot[3] = scale_vectors_x(map);
	m_rot[4] = perspective_projection(map);
	m_rot[5] = matrix_scale_z(map);
	m_rot[6] = matrix_mult(matrix_mult(matrix_mult(matrix_mult(m_rot[5],
		m_rot[0]), m_rot[1]), m_rot[2]), m_rot[3]);
	i = 0;
	while (i < map->quantity)
	{
		map->vec_ch[i] = vec_matrix_mult(map->vec[i], m_rot[6]);
		if (map->turned_on < 0)
			map->vec_ch[i] = vec_matrix_mult(map->vec[i],
				matrix_mult(m_rot[6], m_rot[4]));
		map->vec_ch[i].x += map->offset_x;
		map->vec_ch[i].y += map->offset_y;
		map->vec_ch[i].color = map->vec[i].color;
		i++;
	}
	draw_all_lines(map);
}
