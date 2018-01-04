/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:09:31 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 20:32:21 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	//t_mapinfo map;

	if (argc != 2)
		ft_putendl("Usage : ./fdf <filename>");
	else
	{
		int i = ft_atoi_base(argv[1], 16);
		printf("%i\n", i);
		// init(&map);
		// read_func(argv, &map);
		// draw(&map);
		// mlx_hook(map.win, 2, 5, key_function, &map);
		// mlx_hook(map.win, 17, 1L << 17, exit_func, &map);
		// mlx_loop(map.mlx);
	}
	return (0);
}
