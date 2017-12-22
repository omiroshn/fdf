/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:34:20 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/22 15:34:21 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

float	vec_mult(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

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
			mult.m[i][j] =  m.m[i][0] * rhs.m[0][j] +
							m.m[i][1] * rhs.m[1][j] +
							m.m[i][2] * rhs.m[2][j] +
							m.m[i][3] * rhs.m[3][j];
			j++;
		}
		i++;
	}
	return (mult);
}

t_vec	vec_matrix_mult(const t_vec vec, const t_matrix4 rhs)
{
	t_vec	res;
	
	res.x = vec.x * rhs.m[0][0] + vec.y * rhs.m[1][0] + vec.z * rhs.m[2][0] + vec.w * rhs.m[3][0];
	res.y = vec.x * rhs.m[0][1] + vec.y * rhs.m[1][1] + vec.z * rhs.m[2][1] + vec.w * rhs.m[3][1];
	res.z = vec.x * rhs.m[0][2] + vec.y * rhs.m[1][2] + vec.z * rhs.m[2][2] + vec.w * rhs.m[3][2];
	res.w = vec.x * rhs.m[0][3] + vec.y * rhs.m[1][3] + vec.z * rhs.m[2][3] + vec.w * rhs.m[3][3];
	return (res);
}
