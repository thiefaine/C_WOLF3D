/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:38:13 by mdubray           #+#    #+#             */
/*   Updated: 2014/11/09 17:11:05 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		sign;

	if (!str)
		return (0);
	sign = 1;
	nb = 0;
	while (*str == '\v' || *str == '\t' || *str == '\f' || *str == '\r' \
			|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+' && sign > 0)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (sign * nb);
}
