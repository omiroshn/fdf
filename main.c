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

void tests();

int my_key_funct(int keycode, void *param)
{
	int				speed;
	t_mapinfo		*map;
	int				radius;

	speed = 20;
	radius = 20;
	map = (t_mapinfo *)param;
	static double angle_x = 0;
	static double angle_y = 0;
	static double angle_z = 0;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65363)
	{
		//map->vec->x = map->vec->x + speed;
		angle_y += 0.1;
	}
	else if (keycode == 65361)
	{
		//map->vec->x = map->vec->x - speed;
		angle_y -= 0.1;
	}
	else if (keycode == 65362)
	{
		//map->vec->y = map->vec->y - speed;
		angle_x += 0.1;
	}
	else if (keycode == 65364)
	{
		//map->vec->y = map->vec->y + speed;
		angle_x -= 0.1;
	}
	else if (keycode == 49)
	{
		//map->vec->y = map->vec->y + speed;
		angle_z += 0.1;
	}
	else if (keycode == 50)
	{
		//map->vec->y = map->vec->y + speed;
		angle_z -= 0.1;
	}
	draw(map, angle_x, angle_y, angle_z);
	//printf("%i\n", keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mapinfo	map;

	if (argc != 2)
		ft_putstr("Usage : ./fdf <filename>\n");
	else
	{
		//check_content(argv);
		render(&map);
		read_func(argv, &map);
		draw(&map, 0, 0, 0);
		mlx_hook(map.win, 2, 5, my_key_funct, &map);
		mlx_loop(map.mlx);

		//tests();
	}
	return (0);
}

void tests()
{
	// t_vec struc;
	// float lenght;
	// float res;

	// struc.x = 3;
	// struc.y = 1;
	// struc.z = -2;
	// lenght = vec_lenght(struc);
	// struc = vec_normalizing(struc, lenght);
	// printf("✅ lenght: %f\n", lenght);
	// printf("✅ norm: x, y, z: %f %f %f\n", struc.x, struc.y, struc.z);

	// t_vec a;
	// t_vec b;
	// t_vec c;

	// a.x = 3;
	// a.y = -3;
	// a.z = 1;

	// b.x = -12;
	// b.y = 12;
	// b.z = -4;
	// c = vec_crossproduct(a, b);
	// printf("✅ cross: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	// c = vec_add(a, b);
	// printf("✅ add: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	// c = vec_sub(a, b);
	// printf("✅ sub: x, y, z: %.0f %.0f %.0f\n", c.x, c.y, c.z);
	// res = vec_mult(a, b);
	// printf("✅ mult: %.0f\n", res);

	//тесты матриц
	// t_matrix4 res;
	// t_matrix4 rhs = {{
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4}
	// }};
	// res = matrix_mult(rhs, rhs);
	// for (int i = 0; i < 4; ++i)
	// {
	// 	for (int j = 0; j < 4; ++j)
	// 	{
	// 		printf("%0.f ", res.m[i][j]);
	// 	}
	// 	printf("\n");
	// }

	// t_vec vec;
	// t_vec res;
	// vec.x = 1;
	// vec.y = 2;
	// vec.z = 3;
	// vec.w = 1;

	// t_matrix4 rhs = {{
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4},
	// 	{1, 2, 3, 4}
	// }};

	// res = vec_matrix_mult(vec, rhs);
	// printf("vec_matrix_mult: x, y, z, w: %f %f %f %f\n", res.x, res.y, res.z, res.w);
}