/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:00:45 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/30 06:04:29 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

float	vec_lenght(t_vec struc)
{
	return (sqrt(struc.x * struc.x +
		struc.y * struc.y + struc.z * struc.z));
}

t_vec	vec_normalizing(t_vec struc, float lenght)
{
	float invlen;

	invlen = 0;
	if (lenght > 0)
	{
		invlen = 1 / lenght;
		struc.x *= invlen;
		struc.y *= invlen;
		struc.z *= invlen;
	}
	return (struc);
}

/*
** Returning an orthogonal vector (перпендикулярный)
** в основном используется для создания системы координат
** pseudo vector
*/

t_vec	vec_crossproduct(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	t_vec c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}
