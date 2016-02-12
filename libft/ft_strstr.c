/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:45:14 by mdubray           #+#    #+#             */
/*   Updated: 2014/11/09 13:44:17 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*start;
	size_t	len;

	len = ft_strlen(s2);
	if (!s2 || !len || !s1)
		return ((char *)s1);
	start = (char *)s1;
	while ((start = ft_strchr(start, *s2)))
	{
		if (!ft_strncmp(start, s2, len))
			return (start);
		start++;
	}
	return (NULL);
}
