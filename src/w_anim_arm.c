/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_anim_arm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 16:55:34 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/20 00:37:08 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		anim_arm(t_env *e)
{
	e->anim = 1;
	draw_arm(e);
	e->anim = 0;
	e->space = 0;
	return (0);
}

void	draw_arm(t_env *e)
{
	int		w;
	int		h;
	int		y;
	int		y_p;

	y = e->height;
	w = 125;
	h = 74;
	e->img = mlx_new_image(e->mlx, w, h);
	e->img = mlx_xpm_file_to_image(e->mlx, "xpm/arm.xpm", &w, &h);
	while (y >= e->height - h + 10)
	{
		y_p = y / 3;
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->width / 2 - y_p, y);
		expose_hook(e);
		y -= 10;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, e->width / 2, y);
}
