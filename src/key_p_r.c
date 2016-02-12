/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_p_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 18:16:58 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 17:37:26 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	reset_controls(t_env *e)
{
	e->up = 0;
	e->down = 0;
	e->left = 0;
	e->right = 0;
	e->straff_r = 0;
	e->straff_l = 0;
	e->space = 0;
	e->anim = 0;
}

int		key_p(int keycode, t_env *e)
{
	if (keycode == 'w' && e->game == 1)
		e->up = 1;
	if (keycode == 's' && e->game == 1)
		e->down = 1;
	if (keycode == 'a' && e->game == 1)
		e->left = 1;
	if (keycode == 'd' && e->game == 1)
		e->right = 1;
	if (keycode == 65361 && e->game == 1)
		e->straff_l = 1;
	if (keycode == 65363 && e->game == 1)
		e->straff_r = 1;
	if (keycode == 32 && e->game == 1 && e->anim == 0)
		e->space = 1;
	if (keycode == 65307)
		exit(0);
	key_p_other(keycode, e);
	return (0);
}

int		key_p_other(int keycode, t_env *e)
{
	if (keycode == 'k' && e->game == 1)
	{
		if (w_save(e) == 0)
			mlx_string_put(e->mlx, e->win, 250, 140, 0xFF0000, "Fail saving.");
	}
	if (keycode == 'o' && e->game != 2)
	{
		e->prev_game = e->game;
		e->game = 2;
		reset_controls(e);
		draw_settings(e);
	}
	if (keycode == 'i' && e->game == 2)
	{
		e->game = e->prev_game;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	return (0);
}

int		key_r(int keycode, t_env *e)
{
	if (keycode == 'w' && e->game == 1)
		e->up = 0;
	if (keycode == 's' && e->game == 1)
		e->down = 0;
	if (keycode == 'a' && e->game == 1)
		e->left = 0;
	if (keycode == 'd' && e->game == 1)
		e->right = 0;
	if (keycode == 65361 && e->game == 1)
		e->straff_l = 0;
	if (keycode == 65363 && e->game == 1)
		e->straff_r = 0;
	return (0);
}

int		move(t_env *e)
{
	if (e->up == 1)
		move_up(e);
	if (e->down == 1)
		move_down(e);
	if (e->left == 1)
		rotate_left(e);
	if (e->right == 1)
		rotate_right(e);
	if (e->space == 1)
		anim_arm(e);
	if (e->straff_l == 1 && e->set->straff == 1)
		straff_l(e);
	if (e->straff_r == 1 && e->set->straff == 1)
		straff_r(e);
	if (e->left == 1 || e->right == 1 || e->up == 1 || e->down == 1 \
			|| e->straff_l == 1 || e->straff_r == 1)
		expose_hook(e);
	return (0);
}
