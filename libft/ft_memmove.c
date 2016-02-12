/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:56:10 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:06:00 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	str[n];

	if (!dst || !src)
		return (NULL);
	ft_memcpy(str, src, n);
	ft_memcpy(dst, str, n);
	return (dst);
}
