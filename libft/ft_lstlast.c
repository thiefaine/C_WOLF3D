/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 16:49:35 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/06 16:49:38 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *begin_list)
{
	t_list *end;

	end = begin_list;
	while (end->next != NULL)
		end = end->next;
	return (end);
}
