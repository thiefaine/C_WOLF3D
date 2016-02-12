/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:31:26 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:19:36 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*ptr;

	if (!dst || !src)
		return (NULL);
	ptr = dst;
	while (src && *src && ptr && n != 0)
	{
		*(ptr++) = *(src++);
		n--;
	}
	while (n != 0 && src && ptr)
	{
		*(ptr++) = '\0';
		n--;
	}
	return (dst);
}
