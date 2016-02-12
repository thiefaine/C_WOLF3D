/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_manage_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:12:13 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 18:18:08 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		manage_cursor_light(int x, int y, t_env *e)
{
	double	l;

	if (x >= 200 && x <= 400 && y >= 3 * e->height / 6 \
			&& y <= 3 * e->height / 6 + 12)
	{
		l = (((float)x - 200) / 200) * 10;
		l = (l - floor(l) <= 0.5) ? floor(l) : ceil(l);
		e->set->light = l;
		expose_hook(e);
	}
}

void		manage_color(int x, int y, t_env *e)
{
	if (x >= 200 && x <= 236 && y >= e->height / 6 \
			&& y <= e->height / 6 + 12 && e->set->color == 1)
	{
		e->set->color = 0;
		expose_hook(e);
	}
	else if (x >= 200 && x <= 236 && y >= e->height / 6 \
			&& y <= e->height / 6 + 12 && e->set->color == 0)
	{
		e->set->color = 1;
		expose_hook(e);
	}
}

void		manage_straff(int x, int y, t_env *e)
{
	if (x >= 200 && x <= 236 && y >= 5 * e->height / 6 \
			&& y <= (5 * e->height / 6) + 12 && e->set->straff == 1)
	{
		e->set->straff = 0;
		expose_hook(e);
	}
	else if (x >= 200 && x <= 236 && y >= 5 * e->height / 6 \
			&& y <= (5 * e->height / 6) + 12 && e->set->straff == 0)
	{
		e->set->straff = 1;
		expose_hook(e);
	}
}

void		w_detect_settings(int button, int x, int y, t_env *e)
{
	if (button == 1 && e->game == 2)
	{
		manage_color(x, y, e);
		manage_straff(x, y, e);
		manage_cursor_light(x, y, e);
		if (x >= 5 && x <= 45 && y >= 5 && y <= 45)
		{
			mlx_clear_window(e->mlx, e->win);
			e->game = e->prev_game;
			expose_hook(e);
		}
	}
}
