/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_get_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:13:55 by mdubray           #+#    #+#             */
/*   Updated: 2016/02/12 08:04:20 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		w_size(char *file)
{
	int		fd;
	char	*line;
	int		nb;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	nb = 0;
	while (get_next_line(fd, &line))
		nb++;
	return (nb);
}

char	***w_get_number(t_env *e)
{
	int		fd;
	int		i;
	char	*line;

	ft_putendl("\033[1;36;40mLoading map...\033[0m");
	line = NULL;
	i = 0;
	if ((fd = open(e->file, O_RDONLY)) < 0)
		return (NULL);
	if (!(e->map = (char ***)malloc(w_size(e->file) * sizeof(char **) + 1)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		e->map[i] = (char **)malloc(ft_strlen(line) / 2 * sizeof(char *) + 1);
		if (!e->map[i])
			return (NULL);
		e->map[i] = ft_strsplit(line, ' ');
		i++;
	}
	e->height_m = i - 1;
	e->map[i] = 0;
	if (close(fd) == -1)
		return (NULL);
	return (e->map);
}
