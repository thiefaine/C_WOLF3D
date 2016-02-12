/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:49:55 by mdubray           #+#    #+#             */
/*   Updated: 2014/12/30 18:02:16 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_map.h"

int		e_check_arg(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	e_init(t_env *e, char **av)
{
	e->dim.y = 500;
	e->dim.x = 9 * e->dim.y / 16;
	e->m->dim.y = ft_atoi(av[1]);
	e->m->dim.x = ft_atoi(av[2]);
	e->map = NULL;
	e->map = e_convert(e, ft_atoi(av[1]), ft_atoi(av[2]));
}

int		expose_hook(t_env *e)
{
	e_draw(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 3 || !av)
	{
		ft_putendl_fd("wrong number of arg", 2);
		return (0);
	}
	if (e_check_arg(ac, av) == 0)
	{
		ft_putendl_fd("wrong format of arg", 2);
		return (0);
	}
	e_init(&e, av);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.dim.y, e.dim.x, "edit map");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
