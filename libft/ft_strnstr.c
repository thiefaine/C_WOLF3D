/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:05:47 by mdubray           #+#    #+#             */
/*   Updated: 2014/11/09 13:17:32 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*start;
	char	*max;
	size_t	len;

	len = ft_strlen(s2);
	max = (char *)(s1 + n);
	if (!s2 || !len || !s1)
		return ((char *)s1);
	start = (char *)s1;
	while ((start = ft_strchr(start, *s2)) && start <= max)
	{
		if (start + len <= max && !ft_strncmp(start, s2, len))
			return (start);
		start++;
	}
	return (NULL);
}
