/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <omiroshn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 22:45:40 by omiroshn          #+#    #+#             */
/*   Updated: 2018/01/04 17:13:02 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_inbase(char c, int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= '9')
			return (1);
		return (0);
	}
	else
	{
		if ((c >= '0' && c <= '9')
			|| (c >= 'A' && c <= ('A' + base - 10)))
			return (1);
		return (0);
	}
}

static int	is_delimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi_base(char *str, int base)
{
	int value;
	int minus;

	if (str == NULL)
		return (16777215);
	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	str += 2;
	while (is_delimiter(*str))
		str++;
	minus = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (is_inbase(*str, base))
	{
		if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * minus);
}
