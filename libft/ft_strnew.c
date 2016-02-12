/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:14:28 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 13:28:01 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	ft_bzero(str, size);
	return (str);
}
