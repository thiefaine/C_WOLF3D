/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:27:21 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:13:45 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = dst;
	while (src && ptr && *src)
		*(ptr++) = *(src++);
	*ptr = '\0';
	return (dst);
}
