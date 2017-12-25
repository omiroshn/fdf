#include "header.h"

void render(t_mapinfo *sys)
{
	sys->mlx = mlx_init();
	sys->win = mlx_new_window(sys->mlx, WIDTH, HEIGHT, "omiroshn's fdf");
}