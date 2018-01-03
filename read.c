/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:42:07 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/03 23:05:08 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_countwords(char *str, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		result++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (result);
}

static int	gnl_values(char *filename)
{
	int		fd;
	char	*lol;

	lol = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error opening file.\n");
		exit(-1);
	}
	get_next_line(fd, &lol);
	close(fd);
	return (ft_countwords(lol, ' '));
}

static int	lenth_of_fdf(char *filename)
{
	int		fd;
	char	*lol;
	int		lenght;

	lenght = 0;
	lol = NULL;
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

void		read_func(char **argv, t_mapinfo *map)
{
	int	i;
	int	j;
	int	fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		printf("error fd read_func");
	map->lines = lenth_of_fdf(argv[1]);
	map->values = gnl_values(argv[1]);
	map->quantity = map->values * map->lines;
	map->vec = (t_vec *)malloc(sizeof(t_vec) * map->quantity);
	map->numbers = (int **)malloc(sizeof(int *) * map->lines);
	i = 0;
	while (i < map->lines)
	{
		map->numbers[i] = (int *)malloc(sizeof(int) * map->values);
		get_next_line(fd, &map->lol);
		map->map = ft_strsplit(map->lol, ' ');
		j = 0;
		while (j < map->values)
		{
			map->color = ft_strsplit(map->map[j], ',');
			map->numbers[i][j] = ft_atoi(map->map[j]);
			if (map->color[1] == NULL)
				map->color[1] = "0xFFFFFF";
			map->vec[i * map->values + j].color = ft_atoi_base(map->color[1], 16);
			j++;
		}
		i++;
	}
	transform(map);
}
