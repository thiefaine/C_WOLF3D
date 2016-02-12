/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:49:54 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/06 16:49:55 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *src;
	t_list *dest;
	t_list *begin;

	src = lst;
	dest = f(src);
	begin = dest;
	while (src->next != NULL)
	{
		dest->next = f(src->next);
		dest = dest->next;
		src = src->next;
	}
	return (begin);
}
