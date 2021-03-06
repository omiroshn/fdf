/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:52:51 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 17:16:45 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_strsplit(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
