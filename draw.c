#include "header.h"

int my_key_funct(int keycode, void *param)
{
	int				speed;
	t_mapinfo		*map;
	int				i;

	speed = 3;
	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
		map->angle_y += 0.1;
	else if (keycode == 123)
		map->angle_y -= 0.1;
	else if (keycode == 126)
		map->angle_x += 0.1;
	else if (keycode == 125)
		map->angle_x -= 0.1;
	else if (keycode == 18)
		map->angle_z += 0.1;
	else if (keycode == 19)
		map->angle_z -= 0.1;
	else if (keycode == 13)
	{
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y - speed;
			i++;
		}
	}
	else if (keycode == 1)
	{
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y + speed;
			i++;
		}
	}
	else if (keycode == 0)
	{
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x - speed;
			i++;
		}
	}
	else if (keycode == 2)
	{
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x + speed;
			i++;
		}
	}
	draw(map);
	return (0);
}

void draw(t_mapinfo *map)
{
	t_matrix4	rot[4];
	t_vec		vec;
	int			i;

	rot[0] = rotate_vectors_x(map);
	rot[1] = rotate_vectors_y(map);
	rot[2] = rotate_vectors_z(map);
	rot[3] = matrix_mult(matrix_mult(rot[0], rot[1]), rot[2]);
	i = 0;
	while (i < map->quantity)
	{
		vec = vec_matrix_mult(map->vec[i], rot[3]);
		mlx_pixel_put(map->mlx, map->win, vec.x, vec.y, 0xFFFFFF);
		i++;
	}
}

t_matrix4 rotate_vectors_x(t_mapinfo *map)
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

t_matrix4 rotate_vectors_y(t_mapinfo *map)
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

t_matrix4 rotate_vectors_z(t_mapinfo *map)
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