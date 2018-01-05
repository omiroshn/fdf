/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 01:11:09 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 16:38:37 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_error(char *str)
{
	ft_putendl(str);
	exit(-1);
}

int		exit_func(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}
