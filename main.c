/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:09:31 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/27 18:55:04 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void tests();

int		main(int argc, char **argv)
{
	t_mapinfo	map;

	if (argc != 2)
		ft_putstr("Usage : ./fdf <filename>\n");
	else
	{
		init(&map);
		read_func(argv, &map);
		draw(&map, 0);
		mlx_hook(map.win, 2, 5, my_key_funct, &map);
		mlx_hook(map.win, 17, 1L << 17, exit_x, &map);
		mlx_loop(map.mlx);
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