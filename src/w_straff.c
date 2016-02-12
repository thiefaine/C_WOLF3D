/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_straff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 03:08:26 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 16:59:24 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	straff_l(t_env *e)
{
	t_coord	pos;
	t_coord	pos_v;
	int		r;
	double	m;

	r = 90;
	m = 0.2;
	pos.x = e->cam->pos.x;
	pos.y = e->cam->pos.y;
	pos_v.x = pos.x - (e->cam->dir.x * cos(r) - e->cam->dir.y * sin(r)) * m;
	pos_v.y = pos.y - (e->cam->dir.x * sin(r) - e->cam->dir.y * cos(r)) * m;
	if (ft_atoi(e->map[(int)pos_v.x][(int)pos.y]) == 0)
		e->cam->pos.x -= (e->cam->dir.x * cos(r) - e->cam->dir.y * sin(r)) * m;
	if (ft_atoi(e->map[(int)pos.x][(int)pos_v.y]) == 0)
		e->cam->pos.y -= (e->cam->dir.x * sin(r) + e->cam->dir.y * cos(r)) * m;
}

void	straff_r(t_env *e)
{
	t_coord	pos;
	t_coord	pos_v;
	int		r;
	double	m;

	r = 90;
	m = 0.2;
	pos.x = e->cam->pos.x;
	pos.y = e->cam->pos.y;
	pos_v.x = pos.x + (e->cam->dir.x * cos(r) - e->cam->dir.y * sin(r)) * m;
	pos_v.y = pos.y + (e->cam->dir.x * sin(r) - e->cam->dir.y * cos(r)) * m;
	if (ft_atoi(e->map[(int)pos_v.x][(int)pos.y]) == 0)
		e->cam->pos.x += (e->cam->dir.x * cos(r) - e->cam->dir.y * sin(r)) * m;
	if (ft_atoi(e->map[(int)pos.x][(int)pos_v.y]) == 0)
		e->cam->pos.y += (e->cam->dir.x * sin(r) - e->cam->dir.y * cos(r)) * m;
}
