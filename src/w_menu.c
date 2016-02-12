/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_menu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:14:08 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 17:45:04 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			w_detect_menu(int button, int x, int y, t_env *e)
{
	if (button == 1 && e->game == 0)
	{
		if (x >= 10 && x <= e->width - 10 && y <= e->height / 3 - 10 && y >= 10)
		{
			e->game = 1;
			w_foreach(e);
		}
		else if (x >= 10 && x <= e->width - 10 && y <= 2 * e->height / 3 + 10 \
				&& y >= e->height / 3 + 10)
		{
			e->game = 1;
			w_load(e);
			w_check_load(e);
			w_foreach(e);
		}
		else if (x >= 10 && x <= e->width - 10 && y <= e->height - 10 \
				&& y >= 2 * e->height / 3 + 10)
		{
			e->game = 2;
			expose_hook(e);
		}
	}
	return (0);
}

void		w_draw_img(t_env *e)
{
	int		w;
	int		h;
	int		y;

	w = 77;
	h = 12;
	y = e->height / 6;
	e->img = mlx_new_image(e->mlx, w, h);
	e->img = mlx_xpm_file_to_image(e->mlx, "xpm/new_game.XPM", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->width / 2 - w / 2, y);
	y = 3 * e->height / 6;
	e->img = mlx_xpm_file_to_image(e->mlx, "xpm/continue.XPM", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->width / 2 - w / 2, y);
	y = 5 * e->height / 6;
	e->img = mlx_xpm_file_to_image(e->mlx, "xpm/settings.XPM", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->width / 2 - w / 2, y);
}

void		w_draw_menu(t_env *e)
{
	t_coord	p1;
	t_coord	p2;

	p1.x = 10;
	p1.y = 10;
	p2.x = e->width - 10;
	p2.y = (e->height / 3) - 10;
	w_draw_square(e, p1, p2, 0xbbbbbb);
	p1.y = (e->height / 3) + 10;
	p2.y = (2 * e->height / 3) - 10;
	w_draw_square(e, p1, p2, 0xbbbbbb);
	p1.y = (2 * e->height / 3) + 10;
	p2.y = e->height - 10;
	w_draw_square(e, p1, p2, 0xbbbbbb);
	w_draw_img(e);
}
