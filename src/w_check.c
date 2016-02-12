/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 20:01:00 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 20:08:27 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	w_test_len(char *l)
{
	static char	*line = NULL;

	if (line == NULL)
		line = ft_strdup(l);
	if (ft_strlen(line) != ft_strlen(l))
	{
		ft_putendl_fd("\033[1;33;40mMAP FAIL \033[0m: different width", 2);
		exit(0);
	}
}

void	detect_spot(t_env *e, char *line, int y)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
		{
			ft_putstr_fd("\033[1;33;40mMAP FAIL \033[0m: bad character\n", 2);
			exit(0);
		}
		e->disp = (line[i] == '0') ? 1 : e->disp;
		if (e->disp == 1 && e->spot_placed == 0)
		{
			e->cam->pos.x = i / 2 + 0.5;
			e->cam->pos.y = y + 0.5;
			e->spot_placed = 1;
		}
		i++;
	}
}

int		w_check_map(t_env *e)
{
	int		i;
	int		fd;
	char	*line;

	ft_putendl("\033[1;33;40mChecking map...\033[0m");
	if ((fd = open(e->file, O_RDONLY)) == -1)
		return (1);
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		w_test_len(line);
		e->width_m = ft_strlen(line) / 2;
		detect_spot(e, line, i);
		i++;
	}
	return (e->disp == 0) ? 2 : 0;
}

void	w_check_out(t_env *e)
{
	int		err;

	if (ft_strcmp(e->file, "story") == 0)
		e->file = ft_strdup("maps/map_big.txt");
	err = w_check_map(e);
	if (err == 1)
		ft_putstr_fd("\033[1;33;40mMAP FAIL \033[0m: can't open map\n", 2);
	if (err == 2)
		ft_putstr_fd("\033[1;33;40mMAP FAIL \033[0m: no spot for player\n", 2);
	if (err == 3)
		ft_putstr_fd("\033[1;33;40mMAP FAIL \033[0m: bad character\n", 2);
	if (err > 0)
		exit(0);
	if ((e->map = w_get_number(e)) == NULL)
	{
		ft_putendl_fd("\033[1;33;40mMAP FAIL \033[0m: can't create map", 2);
		exit(0);
	}
	w_check_walls(e);
	ft_putendl("\033[1;32;40mReady\033[0m");
}

void	w_check_load(t_env *e)
{
	if (e->cam->pos.x < 0 || e->cam->pos.x > e->height_m || e->cam->pos.y < 0 \
			|| e->cam->pos.y > e->width_m)
	{
		ft_putendl_fd("Error saved data", 2);
		exit(0);
	}
	if (e->set->color < 0 || e->set->color > 1)
		e->set->color = 0;
	if (e->set->light < 0 || e->set->light > 10)
		e->set->light = 5;
}
