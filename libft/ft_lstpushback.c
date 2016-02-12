/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:50:23 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/07 19:00:37 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *begin;

	begin = *alst;
	if (alst)
	{
		if (new)
		{
			while (begin->next != NULL)
				begin = begin->next;
			begin->next = new;
			new->next = NULL;
		}
	}
	else
	{
		if (new)
		{
			begin = new;
			new->next = NULL;
		}
	}
}
