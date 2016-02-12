/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:20:13 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/23 18:13:37 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*ret;
	int		b;
	int		e;
	int		i;

	b = 0;
	e = ft_strlen(s);
	ret = (char *)malloc(e * sizeof(char) + 1);
	if (!ret || !s)
		return (NULL);
	while ((s[b] == ' ' || s[b] == '\t' || s[b] == '\n') || s[b] == '\0')
		b++;
	while ((s[e] == ' ' || s[e] == '\t' || s[e] == '\n') || s[e] == '\0')
		e--;
	i = 0;
	while (b <= e)
	{
		ret[i] = s[b];
		b++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
