/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 16:24:43 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/30 18:02:14 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_map.h"

int		**e_convert(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	e->map = (int **)malloc(e->m->dim.y * sizeof (int *));
	while (i++ <= e->m->dim.y)
	{
		j = -1;
		e->map[i] = (int *)malloc(e->m->dim.x * sizeof (int));
		while (j++ <= e->m->dim.x)
			e->map[i][j] = 1;
	}
	return (e->map);
}
