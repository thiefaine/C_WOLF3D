/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_save.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:15:06 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 17:44:58 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		w_load(t_env *e)
{
	int		ret;
	char	buff[2];
	char	*line;
	char	**tab;
	int		fd;

	line = (char *)malloc(1 * sizeof(char) + 1);
	tab = NULL;
	ft_bzero(buff, 2);
	fd = open(ft_strjoin("save/", e->file), O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buff, 1)) > 0)
		line = ft_strjoin(line, buff);
	tab = ft_strsplit(line, '\n');
	e->cam->pos.x = w_load_env(tab[0]);
	e->cam->pos.y = w_load_env(tab[1]);
	e->cam->dir.x = w_load_env(tab[2]);
	e->cam->dir.y = w_load_env(tab[3]);
	e->cam->fov.x = w_load_env(tab[4]);
	e->cam->fov.y = w_load_env(tab[5]);
	e->set->color = w_load_env(tab[6]);
	e->set->light = w_load_env(tab[7]);
	close(fd);
	return (0);
}

double	w_load_env(char *line)
{
	double	nb;

	nb = ft_atoi(line);
	nb /= 100;
	return (nb);
}

int		w_save(t_env *e)
{
	int		fd;
	t_coord	pt1;
	t_coord	pt2;

	pt1.x = 10;
	pt1.y = 10;
	pt2.x = 80;
	pt2.y = 25;
	w_draw_square(e, pt1, pt2, 0xaf8412);
	mlx_string_put(e->mlx, e->win, 20, 20, 0x000000, "saving...");
	mlx_string_put(e->mlx, e->win, 21, 21, 0xffffff, "saving...");
	usleep(1000);
	fd = open(ft_strjoin("save/", e->file), O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		return (0);
	w_save_env(e, fd);
	if (close(fd) < 0)
		return (0);
	return (1);
}

void	w_save_env(t_env *e, int fd)
{
	ft_putendl_fd(ft_itoa(e->cam->pos.x * 100), fd);
	ft_putendl_fd(ft_itoa(e->cam->pos.y * 100), fd);
	ft_putendl_fd(ft_itoa(e->cam->dir.x * 100), fd);
	ft_putendl_fd(ft_itoa(e->cam->dir.y * 100), fd);
	ft_putendl_fd(ft_itoa(e->cam->fov.x * 100), fd);
	ft_putendl_fd(ft_itoa(e->cam->fov.y * 100), fd);
	ft_putendl_fd(ft_itoa(e->set->color * 100), fd);
	ft_putendl_fd(ft_itoa(e->set->light * 100), fd);
}
