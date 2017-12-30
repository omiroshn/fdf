/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 05:13:49 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/30 09:04:00 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	arrow_keys(int keycode, t_mapinfo *map)
{
	char *str;

	str = "";
	if (keycode == 53)
		exit(0);
	else if (keycode == 124 && (str = "right"))
		map->angle_y += 0.1;
	else if (keycode == 123 && (str = "left"))
		map->angle_y -= 0.1;
	else if (keycode == 126 && (str = "up"))
		map->angle_x += 0.1;
	else if (keycode == 125 && (str = "down"))
		map->angle_x -= 0.1;
	else if (keycode == 18 && (str = "z-left"))
		map->angle_z -= 0.1;
	else if (keycode == 19 && (str = "z-right"))
		map->angle_z += 0.1;
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
}

void	wasd_keys(int keycode, t_mapinfo *map)
{
	char *str;

	str = "";
	map->speed = 10;
	if (keycode == 13 && (str = "up"))
		map->offset_y -= map->speed;
	else if (keycode == 1 && (str = "down"))
		map->offset_y += map->speed;
	else if (keycode == 0 && (str = "left"))
		map->offset_x -= map->speed;
	else if (keycode == 2 && (str = "right"))
		map->offset_x += map->speed;
	else if (keycode == 6 && (str = "Z"))
		map->offset_z -= map->speed;
	else if (keycode == 7 && (str = "X"))
		map->offset_z += map->speed;
	else if (keycode == 78 && (str = "-") && map->scale > 0)
		map->scale -= 2;
	else if (keycode == 69 && (str = "+"))
		map->scale += 2;
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
}

void	help_keys(int keycode, t_mapinfo *map)
{
	char	*str;

	str = "";
	if (keycode == 44 && (str = "?"))
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 70,
			0xCCCCCC, "ZOOM: + -");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 55,
			0xCCCCCC, "Depth: z x");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 40,
			0xCCCCCC, "Moving: WASD");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 25,
			0xCCCCCC, "Rotation: Arrows, 1, 2");
	}
}

int		key_function(int keycode, void *param)
{
	t_mapinfo *map;

	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	arrow_keys(keycode, map);
	wasd_keys(keycode, map);
	help_keys(keycode, map);
	draw(map);
	if (keycode != 44)
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 25,
			0xCCCCCC, "? for help");
	mlx_string_put(map->mlx, map->win, 10, 10, 0xCCCCCC, "button:");
	return (0);
}
