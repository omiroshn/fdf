/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:34:20 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/03 23:04:01 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_matrix4	matrix_mult(const t_matrix4 m, const t_matrix4 rhs)
{
	t_matrix4	mult;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mult.m[i][j] = m.m[i][0] * rhs.m[0][j] +
							m.m[i][1] * rhs.m[1][j] +
							m.m[i][2] * rhs.m[2][j] +
							m.m[i][3] * rhs.m[3][j];
			j++;
		}
		i++;
	}
	return (mult);
}

t_vec		vec_matrix_mult(const t_vec vec, const t_matrix4 rhs)
{
	t_vec	res;

	res.x = vec.x * rhs.m[0][0] + vec.y * rhs.m[1][0]
	+ vec.z * rhs.m[2][0] + vec.w * rhs.m[3][0];
	res.y = vec.x * rhs.m[0][1] + vec.y * rhs.m[1][1]
	+ vec.z * rhs.m[2][1] + vec.w * rhs.m[3][1];
	res.z = vec.x * rhs.m[0][2] + vec.y * rhs.m[1][2]
	+ vec.z * rhs.m[2][2] + vec.w * rhs.m[3][2];
	res.w = vec.x * rhs.m[0][3] + vec.y * rhs.m[1][3]
	+ vec.z * rhs.m[2][3] + vec.w * rhs.m[3][3];
	return (res);
}

float		vec_mult(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_matrix4	matrix_scale_z(t_mapinfo *map)
{
	t_matrix4		rhs;

	rhs.m[0][0] = 1;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 1;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = 0;
	rhs.m[2][2] = map->offset_z;
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}
