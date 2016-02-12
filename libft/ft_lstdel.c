/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:48:23 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/24 12:57:36 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		if ((*alst)->next)
			ft_lstdel(&(*alst)->next, del);
		free(*alst);
		*alst = NULL;
	}
}
