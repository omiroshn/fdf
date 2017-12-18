/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:09:31 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/17 13:09:33 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float	vec_lenght(t_name struc)
{
	return (sqrt(struc.x * struc.x +
		struc.y * struc.y + struc.z * struc.z));
}

t_name	vec_normalizing(t_name struc, float lenght)
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
t_name	vec_cross(t_name a, t_name b)
{
	t_name c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

t_name	vec_add(t_name a, t_name b)
{
	t_name c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_name	vec_sub(t_name a, t_name b)
{
	t_name c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

float	vec_mult(t_name a, t_name b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

int		main(int argc, char const *argv[])
{
	t_name struc;
	float lenght;
	float res;

	struc.x = 3;
	struc.y = 1;
	struc.z = -2;
	lenght = vec_lenght(struc);
	struc = vec_normalizing(struc, lenght);
	printf("✅ lenght: %f\n", lenght);
	printf("✅ norm: x, y, z: %f %f %f\n", struc.x, struc.y, struc.z);

	t_name a;
	t_name b;
	t_name c;

	a.x = 3;
	a.y = -3;
	a.z = 1;

	b.x = -12;
	b.y = 12;
	b.z = -4;
	c = vec_cross(a, b);
	printf("✅ cross: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	c = vec_add(a, b);
	printf("✅ add: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	c = vec_sub(a, b);
	printf("✅ sub: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	res = vec_mult(a, b);
	printf("✅ mult: %.0f\n", res);

	return (0);
}