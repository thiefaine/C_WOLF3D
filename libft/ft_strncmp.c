/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:46:59 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:27:58 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			if (s1[i] - s2[i] < 0)
				return ((unsigned int)s2[i] - (unsigned int)s1[i]);
			else
				return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		}
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
		n--;
	}
	return (0);
}
