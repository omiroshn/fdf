#include "header.h"

void draw(t_mapinfo *map, double angle_x, double angle_y, double angle_z)
{
	t_matrix4	rot[4];
	t_vec		vec;
	int			i;

	rot[0] = rotate_vectors_x(map, angle_x, angle_y, angle_z);
	rot[1] = rotate_vectors_y(map, angle_x, angle_y, angle_z);
	rot[2] = rotate_vectors_z(map, angle_x, angle_y, angle_z);
	rot[3] = matrix_mult(matrix_mult(rot[0], rot[1]), rot[2]);
	i = 0;
	while (i < map->quantity)
	{
		vec = vec_matrix_mult(map->vec[i], rot[3]);
		mlx_pixel_put(map->mlx, map->win, vec.x * 15, vec.y * 15, 0xFFFFFF);
		i++;
	}
}

t_matrix4 rotate_vectors_x(t_mapinfo *map, double angle_x, double angle_y, double angle_z)
{
	t_matrix4 rhs;

	rhs.m[0][0] = 1;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = cos(angle_x);
	rhs.m[1][2] = sin(angle_x);
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = -sin(angle_x);
	rhs.m[2][2] = cos(angle_x);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_y(t_mapinfo *map, double angle_x, double angle_y, double angle_z)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(angle_y);
	rhs.m[0][1] = 0;
	rhs.m[0][2] = -sin(angle_y);
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 1;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = sin(angle_y);
	rhs.m[2][1] = 0;
	rhs.m[2][2] = cos(angle_y);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_z(t_mapinfo *map, double angle_x, double angle_y, double angle_z)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(angle_z);
	rhs.m[0][1] = sin(angle_z);
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = -sin(angle_z);
	rhs.m[1][1] = cos(angle_z);
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