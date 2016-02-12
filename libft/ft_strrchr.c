/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:07:02 by mdubray           #+#    #+#             */
/*   Updated: 2014/11/09 13:24:58 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;
	const char	*end;
	const char	*ret;

	start = s;
	if (!s)
		return ((char *)s);
	end = s + (ft_strlen(s) ? ft_strlen(s) : 0);
	ret = end;
	while (ret && ret >= start)
	{
		if (*ret == (char)c)
			return ((char *)ret);
		ret--;
	}
	return (NULL);
}
