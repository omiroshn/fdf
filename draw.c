/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:41:23 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/27 19:11:50 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int my_key_funct(int keycode, void *param)
{
	int				speed;
	t_mapinfo		*map;
	int				i;
	int				scale_true;
	char			*str;

	speed = 3;
	str = "";
	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
	{
		str = "right";
		map->angle_y += 0.1;
	}
	else if (keycode == 123)
	{
		str = "left";
		map->angle_y -= 0.1;
	}
	else if (keycode == 126)
	{
		str = "up";
		map->angle_x += 0.1;
	}
	else if (keycode == 125)
	{
		str = "down";
		map->angle_x -= 0.1;
	}
	else if (keycode == 18)
	{
		str = "z-left";
		map->angle_z -= 0.1;
	}
	else if (keycode == 19)
	{
		str = "z-right";
		map->angle_z += 0.1;
	}
	else if (keycode == 13)
	{
		str = "up";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y - speed;
			i++;
		}
	}
	else if (keycode == 1)
	{
		str = "down";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y + speed;
			i++;
		}
	}
	else if (keycode == 0)
	{
		str = "left";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x - speed;
			i++;
		}
	}
	else if (keycode == 2)
	{
		str = "right";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x + speed;
			i++;
		}
	}
	else if (keycode == 78)
	{
		str = "-";
		if (map->scale > 0)
			map->scale -= 1;
	}
	else if (keycode == 69)
	{
		str = "+";
		map->scale += 1;
	}
	draw(map, speed);
	mlx_string_put(map->mlx, map->win, 10, 10, 0xCCCCCC, "button:");
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
	//printf("%i\n", keycode);
	return (0);
}

void draw(t_mapinfo *map, int speed)
{
	t_matrix4	matrix_rot[4];
	t_vec		vec;
	int			i;

	matrix_rot[0] = rotate_vectors_x(map);
	matrix_rot[1] = rotate_vectors_y(map);
	matrix_rot[2] = rotate_vectors_z(map);
	matrix_rot[3] = matrix_mult(matrix_mult(matrix_rot[0],
		matrix_rot[1]), matrix_rot[2]);
	i = 0;
	while (i < map->quantity)
	{
		vec = vec_matrix_mult(map->vec[i], matrix_rot[3]);
		mlx_pixel_put(map->mlx, map->win, vec.x * map->scale + WIDTH / 2, vec.y * map->scale + HEIGHT / 2, 0xFFFFFF);
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
