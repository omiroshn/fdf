#include "header.h"

void init_gnl_struct(t_fdf_gnl **gnl)
{
	if ((*gnl = (t_fdf_gnl*)malloc(sizeof(t_fdf_gnl) * BUFF_SIZE)) == NULL)
		printf("malloc error");
	(*gnl)->line = NULL;
	(*gnl)->buffer = NULL;
	if (((*gnl)->buffer = malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		printf("malloc error");
	(*gnl)->fd = -1;
	(*gnl)->ret = -1;
	(*gnl)->arg = NULL;
	(*gnl)->nb_values = 0;
	(*gnl)->nb_lines = 0;
}

// void init_mapinfo(t_mapinfo **map)
// {
// 	if ((*t_mapinfo = (t_mapinfo*)malloc(sizeof(t_mapinfo))) == NULL)
// 		printf("malloc error");
// 	(*map)->lines = 0;
// 	(*map)->mlx = NULL;
// 	(*map)->win = NULL;
// 	(*map)->map = NULL;
// }

// void init_vector(t_vec **vec)
// {
// 	if ((*t_vec = (t_vec*)malloc(sizeof(t_vec))) == NULL)
// 		printf("malloc error");
// 	(*vec)->x = 0;
// 	(*vec)->y = 0;
// 	(*vec)->z = 0;
// 	(*vec)->w = 0;	
// }