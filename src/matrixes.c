/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 05:14:36 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/05 17:18:27 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_matrix4	perspective_projection(void)
{
	t_matrix4		rhs;
	t_persp_proj	proj;

	init_perspective_projection(&proj);
	rhs.m[0][0] = 2 * proj.n / (proj.r - proj.l);
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 2 * proj.n / (proj.t - proj.b);
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = (proj.r + proj.l) / (proj.r - proj.l);
	rhs.m[2][1] = (proj.t + proj.b) / (proj.t - proj.b);
	rhs.m[2][2] = -(proj.f + proj.n) / (proj.f - proj.n);
	rhs.m[2][3] = -1;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = -2 * proj.f * proj.n / (proj.f - proj.n);
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4	scale_vectors_x(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = map->scale;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = map->scale;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = 0;
	rhs.m[2][2] = map->scale;
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4	rotate_vectors_x(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = 1;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = cos(map->angle_x);
	rhs.m[1][2] = sin(map->angle_x);
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = -sin(map->angle_x);
	rhs.m[2][2] = cos(map->angle_x);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4	rotate_vectors_y(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(map->angle_y);
	rhs.m[0][1] = 0;
	rhs.m[0][2] = -sin(map->angle_y);
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 1;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = sin(map->angle_y);
	rhs.m[2][1] = 0;
	rhs.m[2][2] = cos(map->angle_y);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4	rotate_vectors_z(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(map->angle_z);
	rhs.m[0][1] = sin(map->angle_z);
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = -sin(map->angle_z);
	rhs.m[1][1] = cos(map->angle_z);
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = 0;
	rhs.m[2][2] = 1;
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}
