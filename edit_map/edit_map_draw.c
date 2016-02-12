/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 16:18:27 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/30 18:02:20 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_map.h"

int		e_get_color(int	cube)
{
	return (cube * 600 + 0xaaaaaa);
}

void	e_draw_cube(int x1, int y1, t_env *e)
{
	int		x;
	int		y;

	y = y1;
	while (y < y1 + 10)
	{
		x = x1;
		while (x < x1 + 10)
		{
			printf("x : %d - y : %d\n", x, y);
			mlx_pixel_put(e->mlx, e->win, x, y, e_get_color(e->map[x][y]));
			x++;
		}
		y++;
	}
}

void	e_draw_map(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->m->dim.y)
	{
		x = 0;
		while (x < e->m->dim.x)
		{
			printf("\033[1;35;40mx : %d - y : %d\033[0m\n", x, y);
			e_draw_cube(x, y, e);
			x += 10;
		}
		y += 10;
	}
}

void	e_draw(t_env *e)
{
	e=e;
	e_draw_map(e);
}
