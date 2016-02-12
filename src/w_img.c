/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_img.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 23:07:06 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/19 23:55:17 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		create_img(t_env *e, t_coord dim, char *file, t_coord pos)
{
	int		x;
	int		y;

	x = (int)dim.x;
	y = (int)dim.y;
	if (e->img)
	{
		free(e->img);
		e->img = NULL;
	}
	e->img = mlx_new_image(e->mlx, x, y);
	e->img = mlx_xpm_file_to_image(e->mlx, file, &x, &y);
	mlx_put_image_to_window(e->mlx, e->win, e->img, pos.x, pos.y);
}
