/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:42:07 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/05 17:08:31 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <time.h>

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

static int	gnl_values(t_mapinfo *map, char *filename)
{
	int		fd;
	char	*lol;
	int		temp;

	lol = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		put_error("Error opening file.");
	get_next_line(fd, &lol);
	map->values = ft_countwords(lol, ' ');
	map->lines++;
	free(lol);
	while (get_next_line(fd, &lol) > 0)
	{
		temp = map->values;
		map->values = ft_countwords(lol, ' ');
		map->lines++;
		free(lol);
		if (map->values != temp)
			put_error("Error opening file.");
	}
	close(fd);
	return (map->values);
}

void		read_func2(t_mapinfo *map, char *filename)
{
	int	i;
	int	j;
	int	fd;

	if ((fd = open(filename, O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		put_error("Error opening file.");
	i = 0;
	while (i < map->lines)
	{
		map->numbers[i] = (int *)malloc(sizeof(int) * map->values);
		get_next_line(fd, &map->lol);
		map->map = ft_strsplit(map->lol, ' ');
		free(map->lol);
		j = 0;
		while (j < map->values)
		{
			map->color = ft_strsplit(map->map[j], ',');
			map->numbers[i][j] = ft_atoi(map->map[j]);
			map->vec[i * map->values + j++].color =
			ft_atoi_base(map->color[1], 16);
			free_strsplit(map->color);
		}
		free_strsplit(map->map);
		i++;
	}
}

void		read_func(char **argv, t_mapinfo *map)
{
	map->values = gnl_values(map, argv[1]);
	map->quantity = map->values * map->lines;
	map->vec = (t_vec *)malloc(sizeof(t_vec) * map->quantity);
	map->numbers = (int **)malloc(sizeof(int *) * map->lines);
	if (HEIGHT > WIDTH)
		map->scale = HEIGHT / map->lines;
	else
		map->scale = WIDTH / map->values;
	read_func2(map, argv[1]);
	transform(map);
}
