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

# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

/*
** math
** open
** read
** write, close
** malloc, free, exit
** perror
** strerror
** minilibx
*/

typedef	struct	s_name
{
	float width;
	float x;
	float y;
	float z;
}				t_name;

float	vec_lenght(t_name struc);
t_name	vec_normalizing(t_name struc, float lenght);
t_name	vec_cross(t_name a, t_name b);
t_name	vec_add(t_name a, t_name b);
t_name	vec_sub(t_name a, t_name b);
float	vec_mult(t_name a, t_name b);

#endif