/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:00:45 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/03 23:03:48 by omiroshn         ###   ########.fr       */
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
