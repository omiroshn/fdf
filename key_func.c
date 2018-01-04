/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 05:13:49 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 15:55:59 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	arrow_keys(int keycode, t_mapinfo *map)
{
	char *str;

	str = "";
	if (keycode == MAC_ESC_BUT)
		exit_func(map);
	else if (keycode == MAC_ARROW_RIGHT && (str = "right"))
		map->angle_y += 0.1;
	else if (keycode == MAC_ARROW_LEFT && (str = "left"))
		map->angle_y -= 0.1;
	else if (keycode == MAC_ARROW_UP && (str = "up"))
		map->angle_x += 0.1;
	else if (keycode == MAC_ARROW_DOWN && (str = "down"))
		map->angle_x -= 0.1;
	else if (keycode == MAC_BUT_1 && (str = "z-left"))
		map->angle_z -= 0.1;
	else if (keycode == MAC_BUT_2 && (str = "z-right"))
		map->angle_z += 0.1;
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
}

void	wasd_keys(int keycode, t_mapinfo *map)
{
	char *str;

	str = "";
	map->speed = 10;
	if (keycode == MAC_BUT_W && (str = "W"))
		map->offset_y -= map->speed;
	else if (keycode == MAC_BUT_S && (str = "S"))
		map->offset_y += map->speed;
	else if (keycode == MAC_BUT_A && (str = "A"))
		map->offset_x -= map->speed;
	else if (keycode == MAC_BUT_D && (str = "D"))
		map->offset_x += map->speed;
	else if (keycode == MAC_BUT_MINUS && (str = "-") && map->scale > 1)
		map->scale -= 2;
	else if (keycode == MAC_BUT_PLUS && (str = "+"))
		map->scale += 2;
	else if (keycode == MAC_BUT_P && (str = "P"))
		map->turned_on *= -1;
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
}

void	help_keys(int keycode, t_mapinfo *map)
{
	char	*str;

	str = "";
	if (keycode == MAC_QUEST_BUT && (str = "?"))
	{
		mlx_clear_window(map->mlx, map->win);
		mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 85,
			0xCCCCCC, "ZOOM: + -");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 70,
			0xCCCCCC, "Depth: z x");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 55,
			0xCCCCCC, "Moving: WASD");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 40,
			0xCCCCCC, "Rotation: Arrows, 1, 2");
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 25,
			0xCCCCCC, "Perspective: P");
	}
}

void	zx_keys(int keycode, t_mapinfo *map)
{
	int		i;
	char	*str;

	str = "";
	i = 0;
	if (keycode == MAC_BUT_X && (str = "X"))
		map->offset_z += 1;
	else if (keycode == MAC_BUT_Z && (str = "Z"))
		map->offset_z -= 1;
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
}

int		key_function(int keycode, void *param)
{
	t_mapinfo *map;

	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	arrow_keys(keycode, map);
	wasd_keys(keycode, map);
	help_keys(keycode, map);
	zx_keys(keycode, map);
	draw(map);
	if (keycode != MAC_QUEST_BUT)
		mlx_string_put(map->mlx, map->win, 10, HEIGHT - 25,
			0xCCCCCC, "? for help");
	mlx_string_put(map->mlx, map->win, 10, 10, 0xCCCCCC, "button:");
	return (0);
}
