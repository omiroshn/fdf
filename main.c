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

static int lenth_of_fdf(char *filename) //doone
{
	int		fd;
	char	*lol;
	int		lenght;

	lenght = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(-1);
	}
	while (get_next_line(fd, &lol) > 0)
	{
		lenght++;
		free(lol);
		lol = NULL; 
	}
	close(fd);
	return (lenght);
}

void read_func(char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	*string;
	char	**splitted;
	int		**numbers = NULL;
	int		lines = 0;
	char 	*lol;

	j = 0;
	lines = lenth_of_fdf(argv[1]);
	if (!(fd = open(argv[1], O_RDONLY)))
		return ;
	while (j < lines)
	{
		i = 0;
		get_next_line(fd, &lol);
		splitted = ft_strsplit(string, ' ');
		//numbers = (int *)malloc(sizeof(int *) * 30);
		while (splitted[i])
		{
			//numbers[i] = (int)malloc(sizeof(int) * lines);
			numbers[j][i] = ft_atoi(splitted[i]);
			//printf("%i", numbers[i++]);
		}
		printf("\n");
		j++;
	}
}

int my_key_funct(int keycode, void *param)
{
	int speed;
	int i;
	t_system *sys;
	
	i = 0;
	speed = 10;
	sys = (t_system *)param;
	mlx_clear_window(sys->mlx, sys->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
		sys->vec.x = sys->vec.x + speed;
	else if (keycode == 123)
		sys->vec.x = sys->vec.x - speed;
	else if (keycode == 126)
		sys->vec.y = sys->vec.y - speed;
	else if (keycode == 125)
		sys->vec.y = sys->vec.y + speed;
	while (i < 50)
	{
		mlx_pixel_put(sys->mlx, sys->win, sys->vec.x + i, sys->vec.y, 0xFFFFFF);
		i++;
	}
	//printf("key event %d\n", keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	t_system	sys;
	
	sys.vec.x = 100;
	sys.vec.y = 100;

	//sys.mlx = mlx_init();
	// sys.win = mlx_new_window(sys.mlx, WIDTH, HEIGHT, "tipa fdf");
	read_func(argv);
	// mlx_pixel_put(sys.mlx, sys.win, sys.vec.x, sys.vec.y, 0xFFFFFF);
	// mlx_hook(sys.win, 2, 2, my_key_funct, &sys);
	// mlx_loop(sys.mlx);

	//tests();
	argc++;
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