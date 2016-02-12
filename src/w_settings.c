/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_settings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 21:58:12 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 18:43:23 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		fond(t_env *e, int color)
{
	t_coord	pos1;
	t_coord	pos2;
	int		x;
	int		y;

	pos1.x = 20;
	pos1.y = 20;
	pos2.x = e->width - 20;
	pos2.y = e->height - 20;
	y = pos1.y - 1;
	while (++y <= pos2.y)
	{
		x = pos1.x - 1;
		while (++x <= pos2.x)
			mlx_pixel_put(e->mlx, e->win, x, y, color);
	}
	w_draw_square(e, pos1, pos2, 0x242424);
}

void		w_draw_map_key(t_env *e)
{
	int		x;
	int		y;

	x = 3 * e->width / 4;
	y = e->height / 6;
	mlx_string_put(e->mlx, e->win, x, y, 0x000000, "        Up : w");
	mlx_string_put(e->mlx, e->win, x, y + 15, 0x000000, "      Down : s");
	if (e->set->straff == 1)
	{
		mlx_string_put(e->mlx, e->win, x, y + 30, 0x000000, "      Left : ->");
		mlx_string_put(e->mlx, e->win, x, y + 45, 0x000000, "     Right : <-");
	}
	else
	{
		mlx_string_put(e->mlx, e->win, x, y + 30, 0x999999, "      Left : ->");
		mlx_string_put(e->mlx, e->win, x, y + 45, 0x999999, "     Right : <-");
	}
	mlx_string_put(e->mlx, e->win, x, y + 60, 0x000000, " Cam right : d");
	mlx_string_put(e->mlx, e->win, x, y + 75, 0x000000, "  Cam left : a");
	mlx_string_put(e->mlx, e->win, x, y + 90, 0x000000, "     Punch : space");
	mlx_string_put(e->mlx, e->win, x, y + 105, 0x000000, "      Save : k");
	mlx_string_put(e->mlx, e->win, x, y + 120, 0x000000, " Open menu : o");
	mlx_string_put(e->mlx, e->win, x, y + 135, 0x000000, "Close menu : i");
	mlx_string_put(e->mlx, e->win, x, y + 150, 0x000000, "      Exit : escape");
}

void		w_draw_label(t_env *e)
{
	t_coord	pos;
	t_coord	dim;

	dim.x = 55;
	dim.y = 9;
	pos.x = 100;
	pos.y = e->height / 6;
	create_img(e, dim, "xpm/color.xpm", pos);
	pos.y = 3 * e->height / 6;
	create_img(e, dim, "xpm/light.xpm", pos);
	pos.y = 5 * e->height / 6;
	dim.x = 71;
	create_img(e, dim, "xpm/straff.xpm", pos);
}

void		w_draw_form(t_env *e)
{
	t_coord	pos;
	t_coord	dim;

	dim.x = 30;
	dim.y = 30;
	pos.x = 5;
	pos.y = 5;
	create_img(e, dim, "xpm/close.xpm", pos);
	dim.x = 36;
	dim.y = 12;
	pos.x = 200;
	pos.y = e->height / 6;
	if (e->set->color == 1)
		create_img(e, dim, "xpm/on.xpm", pos);
	else
		create_img(e, dim, "xpm/off.xpm", pos);
	pos.y = 5 * e->height / 6;
	mlx_string_put(e->mlx, e->win, 200, pos.y - 5, 0xff1212, "Beta !");
	if (e->set->straff == 1)
		create_img(e, dim, "xpm/on.xpm", pos);
	else
		create_img(e, dim, "xpm/off.xpm", pos);
	dim.x = 200;
	pos.y = 3 * e->height / 6;
	draw_cursor(e, dim, pos, 0x8904B1);
}

void		draw_settings(t_env *e)
{
	fond(e, 0xd5d5d5);
	w_draw_label(e);
	w_draw_form(e);
	w_draw_map_key(e);
}
