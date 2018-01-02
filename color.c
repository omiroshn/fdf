/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 06:09:40 by omiroshn          #+#    #+#             */
/*   Updated: 2017/12/30 06:58:11 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


// int	clerp(int c1, int c2, double p)
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