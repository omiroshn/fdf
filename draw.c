/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 21:41:23 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/29 22:03:05 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int			clerp(int c1, int c2, double p)
// {
// 	int r;
// 	int g;
// 	int b;

// 	if (c1 == c2)
// 		return (c1);
// 	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
// 	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
// 	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
// 	return (r << 16 | g << 8 | b);
// }


int my_key_funct(int keycode, void *param)
{
	int				speed;
	t_mapinfo		*map;
	int				i;
	int				scale_true;
	char			*str;

	speed = 3;
	str = "";
	map = (t_mapinfo *)param;
	mlx_clear_window(map->mlx, map->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 124)
	{
		str = "right";
		map->angle_y += 0.1;
	}
	else if (keycode == 123)
	{
		str = "left";
		map->angle_y -= 0.1;
	}
	else if (keycode == 126)
	{
		str = "up";
		map->angle_x += 0.1;
	}
	else if (keycode == 125)
	{
		str = "down";
		map->angle_x -= 0.1;
	}
	else if (keycode == 18)
	{
		str = "z-left";
		map->angle_z -= 0.1;
	}
	else if (keycode == 19)
	{
		str = "z-right";
		map->angle_z += 0.1;
	}
	else if (keycode == 13)
	{
		str = "up";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y - speed;
			i++;
		}
	}
	else if (keycode == 1)
	{
		str = "down";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].y = map->vec[i].y + speed;
			i++;
		}
	}
	else if (keycode == 0)
	{
		str = "left";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x - speed;
			i++;
		}
	}
	else if (keycode == 2)
	{
		str = "right";
		i = 0;
		while (i < map->quantity)
		{
			map->vec[i].x = map->vec[i].x + speed;
			i++;
		}
	}
	else if (keycode == 78)
	{
		str = "-";
		if (map->scale > 0)
			map->scale -= 2;
	}
	else if (keycode == 69)
	{
		str = "+";
		map->scale += 2;
	}
	draw(map, speed);
	mlx_string_put(map->mlx, map->win, 10, 10, 0xCCCCCC, "button:");
	mlx_string_put(map->mlx, map->win, 90, 10, 0xFFFFFF, str);
	//printf("%i\n", keycode);
	return (0);
}

void draw_line(t_mapinfo *map, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = x1 >= x0 ? 1 : -1;
  int sy = y1 >= y0 ? 1 : -1;
  
  if (dy <= dx)
  {
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;
    mlx_pixel_put(map->mlx, map->win, x0 + WIDTH / 2, y0  + HEIGHT / 2, 0xFFFFFF);
    for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
    {
      if ( d >0)
      {
        d += d2;
        y += sy;
      }
      else
        d += d1;
      mlx_pixel_put(map->mlx, map->win, x + WIDTH / 2, y + HEIGHT / 2, 0xFFFFFF);
    }
  }
  else
  {
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    mlx_pixel_put(map->mlx, map->win, x0 + WIDTH / 2, y0  + HEIGHT / 2, 0xFFFFFF);
    for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
    {
      if ( d >0)
      {
        d += d2;
        x += sx;
      }
      else
        d += d1;
    mlx_pixel_put(map->mlx, map->win, x + WIDTH / 2, y + HEIGHT / 2, 0xFFFFFF);
    }
  }
}

// mlx_pixel_put(map->mlx, map->win, x0 + WIDTH / 2, y0  + HEIGHT / 2, 0xFFFFFF);
// mlx_pixel_put(map->mlx, map->win, x + WIDTH / 2, y + HEIGHT / 2, 0xFFFFFF);

void draw(t_mapinfo *map, int speed)
{
	t_matrix4	m_rot[5];
	int			i;

	m_rot[0] = rotate_vectors_x(map);
	m_rot[1] = rotate_vectors_y(map);
	m_rot[2] = rotate_vectors_z(map);
	m_rot[3] = scale_vectors_x(map);
	m_rot[4] = matrix_mult(matrix_mult(matrix_mult(m_rot[0], m_rot[1]), m_rot[2]), m_rot[3]);
	i = 0;
	while (i < map->quantity)
	{
		map->vec_ch[i] = vec_matrix_mult(map->vec[i], m_rot[4]);
		//mlx_pixel_put(map->mlx, map->win, map->vec_ch[i].x + WIDTH / 2, map->vec_ch[i].y + HEIGHT / 2, 0xFFFFFF);
		i++;
	}
	// draw_line(map, 1, 1, 1, 5);
	// draw_line(map, 1, 5, 1, 1);
	// draw_line(map, 1, 1, 5, 1);
	// draw_line(map, 5, 1, 1, 1);
	// draw_line(map, 1, 5, 5, 5);
	// draw_line(map, 5, 5, 1, 5);
	// draw_line(map, 5, 1, 5, 5);
	// draw_line(map, 5, 5, 5, 1);
	// draw_line(map, (int)map->vec_ch[0].x, (int)map->vec_ch[2].y, (int)map->vec_ch[0].x, (int)map->vec_ch[0].y);
	// draw_line(map, (int)map->vec_ch[0].x, (int)map->vec_ch[0].y, (int)map->vec_ch[1].x, (int)map->vec_ch[0].y);
	// draw_line(map, (int)map->vec_ch[0].x, (int)map->vec_ch[3].y, (int)map->vec_ch[0].x, (int)map->vec_ch[0].y);
	// draw_line(map, (int)map->vec_ch[0].x, (int)map->vec_ch[0].y, (int)map->vec_ch[1].x, (int)map->vec_ch[0].y);
	i = 0;
	while (i < map->quantity)
	{
		draw_line(map, (int)map->vec_ch[i].x, (int)map->vec_ch[i].y, (int)map->vec_ch[i].x, (int)map->vec_ch[i + 1].y);
		//draw_line(map, (int)map->vec_ch[i].x, (int)map->vec_ch[i].y, (int)map->vec_ch[i + 1].x, (int)map->vec_ch[i].y);
		i++;
	}
}

t_matrix4 scale_vectors_x(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = map->scale;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = map->scale;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = 0;
	rhs.m[2][2] = map->scale;
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_x(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = 1;
	rhs.m[0][1] = 0;
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = cos(map->angle_x);
	rhs.m[1][2] = sin(map->angle_x);
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = -sin(map->angle_x);
	rhs.m[2][2] = cos(map->angle_x);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_y(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(map->angle_y);
	rhs.m[0][1] = 0;
	rhs.m[0][2] = -sin(map->angle_y);
	rhs.m[0][3] = 0;
	rhs.m[1][0] = 0;
	rhs.m[1][1] = 1;
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = sin(map->angle_y);
	rhs.m[2][1] = 0;
	rhs.m[2][2] = cos(map->angle_y);
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}

t_matrix4 rotate_vectors_z(t_mapinfo *map)
{
	t_matrix4 rhs;

	rhs.m[0][0] = cos(map->angle_z);
	rhs.m[0][1] = sin(map->angle_z);
	rhs.m[0][2] = 0;
	rhs.m[0][3] = 0;
	rhs.m[1][0] = -sin(map->angle_z);
	rhs.m[1][1] = cos(map->angle_z);
	rhs.m[1][2] = 0;
	rhs.m[1][3] = 0;
	rhs.m[2][0] = 0;
	rhs.m[2][1] = 0;
	rhs.m[2][2] = 1;
	rhs.m[2][3] = 0;
	rhs.m[3][0] = 0;
	rhs.m[3][1] = 0;
	rhs.m[3][2] = 0;
	rhs.m[3][3] = 1;
	return (rhs);
}
