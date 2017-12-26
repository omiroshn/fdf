#include "header.h"

void draw(t_mapinfo *map, double angle)
{
	int i;
	t_matrix4 rot[4];
	t_vec	vec;

	i = 0;
	map->quantity = map->values * map->lines;
	rot[0] = rotate_vectors_x(map, angle);
	rot[1] = rotate_vectors_y(map, angle);
	rot[2] = rotate_vectors_z(map, angle);
	rot[3] = matrix_mult(matrix_mult(rot[0], rot[1]), rot[2]);
	while (i < map->quantity)
	{
		vec = vec_matrix_mult(map->vec[i], rot[3]);
		mlx_pixel_put(map->mlx, map->win, vec.x * 15, vec.y * 15, 0xFFFFFF);
		i++;
	}
}

t_matrix4 rotate_vectors_x(t_mapinfo *map, double angle)
{
	t_matrix4 rhs;

	rhs.m[0][0] = 1;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = cos(angle);
	rhs.m[1][2] = sin(angle);
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = -sin(angle);
	rhs.m[2][2] = cos(angle);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_y(t_mapinfo *map, double angle)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(angle);
	rhs.m[0][1] = 0;
	rhs.m[0][2] = -sin(angle);
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 1;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = sin(angle);
	rhs.m[2][1] = 0;
	rhs.m[2][2] = cos(angle);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_z(t_mapinfo *map, double angle)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(angle);
	rhs.m[0][1] = sin(angle);
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = -sin(angle);
	rhs.m[1][1] = cos(angle);
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