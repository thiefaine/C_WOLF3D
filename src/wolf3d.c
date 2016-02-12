/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:14:23 by mdubray           #+#    #+#             */
/*   Updated: 2016/02/12 08:31:54 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_init(t_env *e)
{
	e->cam->pos.x = 0;
	e->cam->pos.y = 0;
	e->cam->dir.x = 1;
	e->cam->dir.y = 0;
	e->cam->fov.x = 0;
	e->cam->fov.y = 0.66;
	e->width = 600;
	e->height = 9 * e->width / 16;
	e->map = NULL;
	e->disp = 0;
	e->spot_placed = 0;
	e->game = 0;
	e->prev_game = 0;
	e->anim = 0;
	e->up = 0;
	e->down = 0;
	e->left = 0;
	e->right = 0;
	e->space = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "wolf3d");
	e->img = NULL;
	w_init_settings(e);
}

void	w_init_settings(t_env *e)
{
	e->set->color = 1;
	e->set->light = 5;
	e->set->straff = 0;
}

int		expose_hook(t_env *e)
{
	if (e->game == 1)
		w_foreach(e);
	else if (e->game == 0)
		w_draw_menu(e);
	else if (e->game == 2)
		draw_settings(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->game == 0)
		w_detect_menu(button, x, y, e);
	else if (e->game == 2)
		w_detect_settings(button, x, y, e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;
	t_cam	cam;
	t_set	settings;

	if (!argv[1] || argc != 2)
	{
		ft_putendl_fd("\033[1;33;40mWrong number of argument\033[0m", 2);
		ft_putstr_fd("Wolf3d : \n\t./wolf3d \033[1;32;40myour_map\033[0m", 2);
		ft_putendl_fd(" -> will start an arcade game with your map", 2);
		ft_putendl_fd("\t./wolf3d story -> will start the story mode", 2);
		return (0);
	}
	e.cam = &cam;
	e.set = &settings;
	e.file = ft_strdup(argv[1]);
	w_init(&e);
	w_check_out(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, key_p, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, key_r, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop_hook(e.mlx, &move, &e);
	mlx_loop(e.mlx);
	return (0);
}
