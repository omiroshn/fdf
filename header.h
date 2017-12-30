/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:27:42 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/30 08:16:25 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WIDTH 600
# define HEIGHT 600
# define DWA_PI 2 * 3.141592
# define PI 3.141592
# define PI_2 3.141592 / 2

# include "libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

/*
** ⬆️ 126
** ⬇️ 125
** ▶️ 124
** ◀️ 123
** 1  18
** 2  19
** ESC 53
**
** math
** open
** read
** write, close
** malloc, free, exit
** perror
** strerror
** minilibx
*/

typedef	struct	s_vec
{
	float x;
	float y;
	float z;
	float w;
}				t_vec;

typedef struct	s_matrix4
{
	float		m[4][4];
}				t_matrix4;

typedef struct	s_persp_proj
{
	float angle_of_view;
	float image_aspect_ratio;
	float n;
	float f;
	float b;
	float t;
	float l;
	float r;
	float scale;
}				t_persp_proj;

typedef struct	s_bresenhem
{
	int x0;
	int y0;
	int dx;
	int dy;
	int sx;
	int sy;
	int d;
	int d1;
	int d2;
	int x;
	int y;
}				t_bresenhem;

typedef	struct	s_mapinfo
{
	void		*mlx;
	void		*win;
	t_vec		*vec;
	t_vec		*vec_ch;
	int			lines;
	int			values;
	int			quantity;
	int			**numbers;
	int			min_len_z;
	int			max_len_z;
	char		**map;
	char		*lol;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		scale;
	float		offset_x;
	float		offset_y;
	float		offset_z;
	int			speed;
}				t_mapinfo;

void			init_perspective_projection(t_persp_proj *proj);
void			init_bresenh1(t_bresenhem *a);
void			init_bresenh2(t_bresenhem *a);
void			draw_last_line(t_mapinfo *map, int i);
void			draw_all_lines(t_mapinfo *map);
void			bresenhem_p2(t_mapinfo *map, t_bresenhem *a);
void			bresenhem_p1(t_mapinfo *map, t_bresenhem *a);
void			help_keys(int keycode, t_mapinfo *map);
void			wasd_keys(int keycode, t_mapinfo *map);
void			arrow_keys(int keycode, t_mapinfo *map);
void			draw_line(t_mapinfo *map, t_vec vec1, t_vec vec2);
void			continue_of_lenth_of_z(t_mapinfo *map);
void			lenth_of_z(t_mapinfo *map);
int				exit_func(void *param);
int				key_function(int keycode, void *param);
void			init_center(t_mapinfo *map);
void			init(t_mapinfo *map);
void			draw(t_mapinfo *map);
void			transform(t_mapinfo *map);
void			read_func(char **argv, t_mapinfo *map);
void			check_content(char **argv);
float			vec_lenght(t_vec struc);
float			vec_mult(t_vec a, t_vec b);
t_vec			vec_normalizing(t_vec struc, float lenght);
t_vec			vec_cross(t_vec a, t_vec b);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_matrix_mult(const t_vec vec, const t_matrix4 rhs);
t_matrix4		matrix_mult(const t_matrix4 m, const t_matrix4 rhs);
t_matrix4		rotate_vectors_x(t_mapinfo *map);
t_matrix4		rotate_vectors_y(t_mapinfo *map);
t_matrix4		rotate_vectors_z(t_mapinfo *map);
t_matrix4		scale_vectors_x(t_mapinfo *map);
t_matrix4		perspective_projection(t_mapinfo *map);

#endif
