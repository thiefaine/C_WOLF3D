/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:52:01 by mdubray           #+#    #+#             */
/*   Updated: 2016/02/12 08:01:55 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (s != NULL && f != NULL)
	{
		str = malloc(ft_strlen(s));
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
	}
	return (str);
}
