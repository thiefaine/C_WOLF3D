/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_check_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 19:36:05 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/21 20:06:00 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		w_check_walls(t_env *e)
{
	int		i;
	int		j;
	int		check;

	check = 1;
	j = 0;
	while (e->map[j] != '\0')
	{
		i = 0;
		while (e->map[j][i] != '\0')
		{
			if ((i == 0 || i == e->width_m) || (j == 0 || j == e->height_m))
			{
				if (ft_strcmp(e->map[j][i], "0") == 0)
					check = 0;
			}
			i++;
		}
		j++;
	}
	if (check == 0)
	{
		ft_putendl_fd("\033[1;33;40mMAP FAIL \033[0m: No surrounding walls", 2);
		exit(0);
	}
}
