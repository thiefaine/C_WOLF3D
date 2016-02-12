/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_draw_geometric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 01:45:32 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 18:43:25 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		w_draw_square(t_env *e, t_coord pt1, t_coord pt2, int c)
{
	int		old_pt1_x;
	int		old_pt1_y;

	old_pt1_x = pt1.x;
	old_pt1_y = pt1.y;
	while (pt1.y <= pt2.y)
	{
		pt1.x = old_pt1_x;
		while (pt1.x <= pt2.x)
		{
			if (pt1.x == old_pt1_x || pt1.x == pt2.x)
				mlx_pixel_put(e->mlx, e->win, pt1.x, pt1.y, c);
			if (pt1.y == old_pt1_y || pt1.y == pt2.y)
				mlx_pixel_put(e->mlx, e->win, pt1.x, pt1.y, c);
			pt1.x++;
		}
		pt1.y++;
	}
}

void		w_draw_disc(t_env *e, t_coord pos, int ray, int color)
{
	int		x;
	int		y;

	y = pos.y - ray;
	while (y < pos.y + ray)
	{
		x = pos.x - ray;
		while (x < pos.x + ray)
		{
			if (pow(x - pos.x, 2) + pow(y - pos.y, 2) <= pow(ray, 2))
				mlx_pixel_put(e->mlx, e->win, x, y, color);
			x++;
		}
		y++;
	}
}

void		draw_cursor(t_env *e, t_coord dim, t_coord pos, int color)
{
	t_coord	p_f;
	t_coord	pos2;

	pos2.y = pos.y;
	p_f.x = pos.x + dim.x;
	p_f.y = pos.y + dim.y;
	w_draw_square(e, pos, p_f, color);
	p_f.x = pos.x + (20 * e->set->light);
	while (++pos2.y < p_f.y)
	{
		pos2.x = pos.x;
		while (++pos2.x < p_f.x)
			mlx_pixel_put(e->mlx, e->win, pos2.x, pos2.y, color * 2);
	}
	pos.y += dim.y / 2;
	pos.x += (20 * e->set->light);
	w_draw_disc(e, pos, dim.y + 3, 0xbababa / 2);
	w_draw_disc(e, pos, dim.y + 1, 0xbababa);
}
