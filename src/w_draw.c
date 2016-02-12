/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_draw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:13:27 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/20 06:10:42 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	h_wall(t_var *var, t_env *e, t_draw *d)
{
	int		line_h;

	line_h = abs((int)(e->height / var->wall_dist));
	d->drawb = -line_h / 2 + e->height / 2;
	if (d->drawb < 0)
		d->drawb = 0;
	d->drawe = line_h / 2 + e->height / 2;
	if (d->drawe >= e->height)
		d->drawe = e->height - 1;
}

int		get_color(t_var *var, t_env *e)
{
	if (var->side == 0)
	{
		if (e->cam->pos.x - var->map.x >= 0)
			return (0xaa2222);
		else if (e->cam->pos.x - var->map.x < 0)
			return (0x22aa22);
	}
	else
	{
		if (e->cam->pos.y - var->map.y >= 0)
			return (0x2222aa);
		else if (e->cam->pos.y - var->map.y < 0)
			return (0xaa3377);
	}
	return (0x000000);
}

int		get_other_color(t_var *var, t_env *e)
{
	if (ft_atoi(e->map[(int)var->map.x][(int)var->map.y]) == 1)
		return ((var->side) ? 0xff2424 : 0xff2424 / 2);
	else if (ft_atoi(e->map[(int)var->map.x][(int)var->map.y]) == 2)
		return ((var->side) ? 0x24ac24 : 0x24ac24 / 2);
	else if (ft_atoi(e->map[(int)var->map.x][(int)var->map.y]) == 3)
		return ((var->side) ? 0x2424ff : 0x2424ff / 2);
	else if (ft_atoi(e->map[(int)var->map.x][(int)var->map.y]) == 4)
		return ((var->side) ? 0x841267 : 0x841267 / 2);
	return ((var->side) ? 0x545454 : 0x545454 / 2);
}

void	draw_vert(int x, t_draw *d, t_env *e)
{
	int		i;
	int		l;

	l = e->set->light;
	i = 0;
	while (i <= e->height)
	{
		if (i < d->drawb)
			mlx_pixel_put(e->mlx, e->win, x, i, 0x8888ff + l * 0x0B0B00);
		else if (i >= d->drawb && i <= d->drawe)
			mlx_pixel_put(e->mlx, e->win, x, i, d->color + l * 0x080800);
		else if (i > d->drawe)
			mlx_pixel_put(e->mlx, e->win, x, i, 0x444444 + l * 0x0F0F0F);
		i++;
	}
}

void	draw_line(int x, t_env *e, t_var *var)
{
	t_draw	draw;

	h_wall(var, e, &draw);
	if (e->set->color == 1)
		draw.color = get_color(var, e);
	else
		draw.color = get_other_color(var, e);
	draw_vert(x, &draw, e);
}
