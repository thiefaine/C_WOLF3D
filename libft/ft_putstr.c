/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:15:06 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:08:18 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(const char *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}