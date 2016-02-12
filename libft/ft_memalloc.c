/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:22:31 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/23 17:44:29 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	mem = NULL;
	mem = (void *)malloc(sizeof(void) * size);
	if (!mem)
		return (NULL);
	while (i != size)
		((char *)mem)[i++] = 0;
	return (mem);
}
