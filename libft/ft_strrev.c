/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:14:27 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/05 16:24:40 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		len;
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ret[i] = s[len - 1];
		len--;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
