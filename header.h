/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:27:42 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/18 21:27:43 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define WIDTH 1000
# define HEIGHT 1000
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

typedef	struct	s_mapinfo
{
	t_vec		*vec;
	int			lines;
	int			values;
	int			quantity;
	int			**numbers;
	char		**map;
	char		*lol;
	void		*mlx;
	void		*win;
	float		angle_x;
	float		angle_y;
	float		angle_z;
}				t_mapinfo;

int			exit_x(void *par);
int			my_key_funct(int keycode, void *param);
void		init_center(t_mapinfo *map);
void		init(t_mapinfo *map);
void		draw(t_mapinfo *map);
void		transform(t_mapinfo *map);
void		read_func(char **argv, t_mapinfo *map);
void		init_vector(t_vec **vec);
void		check_content(char **argv);
float		vec_lenght(t_vec struc);
float		vec_mult(t_vec a, t_vec b);
t_vec		vec_normalizing(t_vec struc, float lenght);
t_vec		vec_cross(t_vec a, t_vec b);
t_vec		vec_add(t_vec a, t_vec b);
t_vec		vec_sub(t_vec a, t_vec b);
t_vec		vec_matrix_mult(const t_vec vec, const t_matrix4 rhs);
t_matrix4	matrix_mult(const t_matrix4 m, const t_matrix4 rhs);
t_matrix4	rotate_vectors_x(t_mapinfo *map);
t_matrix4	rotate_vectors_y(t_mapinfo *map);
t_matrix4	rotate_vectors_z(t_mapinfo *map);


#endif