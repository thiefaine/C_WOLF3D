/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_calcul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:31:26 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 19:58:48 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	var_init(t_var *var, t_env *e, double camx)
{
	var->rayp.x = e->cam->pos.x;
	var->rayp.y = e->cam->pos.y;
	var->rayd.x = e->cam->dir.x + e->cam->fov.x * camx;
	var->rayd.y = e->cam->dir.y + e->cam->fov.y * camx;
	var->map.x = (int)var->rayp.x;
	var->map.y = (int)var->rayp.y;
	var->deltad.x = sqrt(1 + pow(var->rayd.y, 2) / pow(var->rayd.x, 2));
	var->deltad.y = sqrt(1 + pow(var->rayd.x, 2) / pow(var->rayd.y, 2));
}

void	side_dist(t_var *var)
{
	var->step.x = 1;
	var->step.y = 1;
	var->sided.x = (var->map.x + 1.0 - var->rayp.x) * var->deltad.x;
	var->sided.y = (var->map.y + 1.0 - var->rayp.y) * var->deltad.y;
	if (var->rayd.x < 0)
	{
		var->step.x = -1;
		var->sided.x = (var->rayp.x - var->map.x) * var->deltad.x;
	}
	if (var->rayd.y < 0)
	{
		var->step.y = -1;
		var->sided.y = (var->rayp.y - var->map.y) * var->deltad.y;
	}
}

void	dda(t_var *var, t_env *e)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (var->sided.x < var->sided.y)
		{
			var->sided.x += var->deltad.x;
			var->map.x += var->step.x;
			var->side = 0;
		}
		else
		{
			var->sided.y += var->deltad.y;
			var->map.y += var->step.y;
			var->side = 1;
		}
		if (ft_atoi(e->map[(int)var->map.x][(int)var->map.y]) > 0)
			hit = 1;
	}
}

void	length_calcul(t_var *v)
{
	double	r;

	if (v->side == 0)
		r = (v->map.x - v->rayp.x + (1.0 - v->step.x) / 2) / v->rayd.x;
	else
		r = (v->map.y - v->rayp.y + (1.0 - v->step.y) / 2) / v->rayd.y;
	v->wall_dist = r;
}

void	w_foreach(t_env *e)
{
	int		x;
	double	camx;
	t_var	var;

	x = 0;
	while (x <= e->width)
	{
		camx = 2 * x / (double)e->width - 1;
		var_init(&var, e, camx);
		side_dist(&var);
		dda(&var, e);
		length_calcul(&var);
		draw_line(x, e, &var);
		x++;
	}
}
