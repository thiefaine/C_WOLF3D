/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:15:41 by mdubray           #+#    #+#             */
/*   Updated: 2016/02/12 08:32:08 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define PI 3.14159265358979323846

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include </usr/X11/include/X11/X.h>

# include "get_next_line.h"
# include "libft.h"

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_cam
{
	t_coord			pos;
	t_coord			dir;
	t_coord			fov;
}					t_cam;

typedef struct		s_set
{
	int				color;
	int				light;
	int				straff;
}					t_set;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*img;
	int				width;
	int				height;
	char			*file;
	t_cam			*cam;
	char			***map;
	int				height_m;
	int				width_m;
	int				disp;
	int				spot_placed;
	int				game;
	int				prev_game;
	int				anim;
	int				up;
	int				down;
	int				right;
	int				left;
	int				straff_l;
	int				straff_r;
	int				space;
	t_set			*set;
}					t_env;

typedef struct		s_var
{
	t_coord			rayp;
	t_coord			rayd;
	t_coord			map;
	t_coord			sided;
	t_coord			deltad;
	t_coord			step;
	double			wall_dist;
	int				side;
}					t_var;

typedef struct		s_draw
{
	int				drawb;
	int				drawe;
	int				color;
}					t_draw;

/*
** Fonctions check
*/

void				w_test_len(char *l);
int					w_check_map(t_env *e);
void				w_check_out(t_env *e);
void				w_check_load(t_env *e);

/*
** Fonctions calcul
*/

void				w_check_walls(t_env *e);

/*
** Fonctions calcul
*/

void				w_foreach(t_env *e);
void				var_init(t_var *var, t_env *e, double camx);
void				side_dist(t_var *var);
void				dda(t_var *var, t_env *e);
void				length_calcul(t_var *v);

/*
** Fonctions draw
*/

void				h_wall(t_var *var, t_env *e, t_draw *d);
int					get_color(t_var *var, t_env *e);
int					get_other_color(t_var *var, t_env *e);
void				draw_vert(int x, t_draw *d, t_env *e);
void				draw_line(int x, t_env *e, t_var *var);

/*
** Fonctions get number
*/

char				***w_get_number(t_env *e);
int					w_size(char *file);

/*
** Fonctions button
*/

void				move_up(t_env *e);
void				move_down(t_env *e);
void				rotate_right(t_env *e);
void				rotate_left(t_env *e);

/*
** Fonctions key_p_r
*/

int					key_p(int keycode, t_env *e);
int					key_p_other(int keycode, t_env *e);
int					key_r(int keycode, t_env *e);
int					move(t_env *e);

/*
** Fonctions menu
*/

int					w_detect_menu(int button, int x, int y, t_env *e);
void				w_draw_img(t_env *e);
void				w_draw_menu(t_env *e);

/*
** Fonctions save
*/

int					w_load(t_env *e);
double				w_load_env(char *line);
int					w_save(t_env *e);
void				w_save_env(t_env *e, int fd);

/*
** Fonctions anim
*/

int					anim_arm(t_env *e);
void				draw_arm(t_env *e);

/*
** Fonctions settings
*/

void				fond(t_env *e, int color);
void				w_draw_map_key(t_env *e);
void				w_draw_label(t_env *e);
void				w_draw_form(t_env *e);
void				draw_settings(t_env *e);

/*
** Fonctions manage settings
*/

void				manage_cursor_light(int x, int y, t_env *e);
void				manage_color(int x, int y, t_env *e);
void				manage_straff(int x, int y, t_env *e);
void				w_detect_settings(int button, int x, int y, t_env *e);

/*
** Fonction image
*/

void				create_img(t_env *e, t_coord dim, char *file, t_coord pos);

/*
** Fonction geometric
*/

void				w_draw_square(t_env *e, t_coord pt1, t_coord pt2, int c);
void				w_draw_disc(t_env *e, t_coord pos, int ray, int color);
void				draw_cursor(t_env *e, t_coord dim, t_coord pos, int color);

/*
** Fonction straff
*/

void				straff_l(t_env *e);
void				straff_r(t_env *e);

/*
** Fonctions main
*/

void				w_init(t_env *e);
void				w_init_settings(t_env *e);
int					key_hook(int keycode, t_env *e);
int					expose_hook(t_env *e);

#endif
