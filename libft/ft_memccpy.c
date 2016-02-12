/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:20:53 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:03:45 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	if (!dst || !src)
		return (NULL);
	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	d = (unsigned char)c;
	while (i < n)
	{
		if ((*s1++ = *s2++) == d)
			return (s1);
		i++;
	}
	return (NULL);
}
