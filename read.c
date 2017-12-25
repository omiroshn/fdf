#include "header.h"

int	ft_countwords(char *str, char c)
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

static int lenth_of_fdf(char *filename)
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

void read_func(char **argv, t_mapinfo *map)
{
	int			i;
	int			j;
	int			fd;

	if ((fd = open(argv[1], O_RDONLY)) < 0)
		printf("error fd read_func");
	map->lines = lenth_of_fdf(argv[1]);
	map->values = gnl_values(argv[1]);
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
			map->numbers[i][j] = ft_atoi(map->map[j]);
			j++;
		}
		i++;
	}
	transform(map);
}
