/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_directions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:12:31 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 16:59:26 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_up(t_env *e)
{
	t_coord	pos;
	double	m;

	m = 0.1;
	pos.x = e->cam->pos.x;
	pos.y = e->cam->pos.y;
	if (ft_atoi(e->map[(int)(pos.x + e->cam->dir.x * m)][(int)pos.y]) == 0)
		e->cam->pos.x += e->cam->dir.x * m;
	if (ft_atoi(e->map[(int)pos.x][(int)(pos.y + e->cam->dir.y * m)]) == 0)
		e->cam->pos.y += e->cam->dir.y * m;
}

void		move_down(t_env *e)
{
	t_coord	pos;
	double	m;

	m = 0.1;
	pos.x = e->cam->pos.x;
	pos.y = e->cam->pos.y;
	if (ft_atoi(e->map[(int)(pos.x - e->cam->dir.x * m)][(int)pos.y]) == 0)
		e->cam->pos.x -= e->cam->dir.x * m;
	if (ft_atoi(e->map[(int)pos.x][(int)(pos.y - e->cam->dir.y * m)]) == 0)
		e->cam->pos.y -= e->cam->dir.y * m;
}

void		rotate_right(t_env *e)
{
	double	old_dirx;
	double	old_fovx;
	double	rot;

	rot = 0.05;
	old_dirx = e->cam->dir.x;
	old_fovx = e->cam->fov.x;
	e->cam->dir.x = e->cam->dir.x * cos(rot) - e->cam->dir.y * sin(rot);
	e->cam->dir.y = old_dirx * sin(rot) + e->cam->dir.y * cos(rot);
	e->cam->fov.x = e->cam->fov.x * cos(rot) - e->cam->fov.y * sin(rot);
	e->cam->fov.y = old_fovx * sin(rot) + e->cam->fov.y * cos(rot);
}

void		rotate_left(t_env *e)
{
	double	old_dirx;
	double	old_fovx;
	double	rot;

	rot = -0.05;
	old_dirx = e->cam->dir.x;
	old_fovx = e->cam->fov.x;
	e->cam->dir.x = e->cam->dir.x * cos(rot) - e->cam->dir.y * sin(rot);
	e->cam->dir.y = old_dirx * sin(rot) + e->cam->dir.y * cos(rot);
	e->cam->fov.x = e->cam->fov.x * cos(rot) - e->cam->fov.y * sin(rot);
	e->cam->fov.y = old_fovx * sin(rot) + e->cam->fov.y * cos(rot);
}
