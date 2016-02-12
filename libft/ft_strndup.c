/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 17:07:21 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:23:54 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *s, size_t n)
{
	char	*scop;

	if (!s)
		return (NULL);
	if ((scop = ((char*)malloc(sizeof(char) * n))))
	{
		ft_strncpy(scop, s, n);
		scop[n] = '\0';
		return (scop);
	}
	return (NULL);
}
