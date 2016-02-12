/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 17:22:37 by mdubray           #+#    #+#             */
/*   Updated: 2016/02/12 08:02:08 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = f(i, s[i]);
			i++;
		}
	}
	return (str);
}
