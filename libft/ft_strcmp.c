/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:52:33 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:27:42 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned int)s1[i] - (unsigned int)s2[i]);
		i++;
	}
	if (s1[i] - s2[i] < 0)
		return (s2[i] - s1[i]);
	else
		return (s1[i] - s2[i]);
}
