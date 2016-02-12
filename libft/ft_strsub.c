/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:37:54 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:25:20 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret || !s)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
