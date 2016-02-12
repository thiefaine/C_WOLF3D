/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:48:36 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/24 12:58:07 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst) = NULL;
	}
}
