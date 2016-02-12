/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:50:40 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/06 16:50:57 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *list)
{
	t_list *begin;
	size_t i;

	begin = list;
	if (!list)
		return (0);
	i = 0;
	while (begin->next)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}
