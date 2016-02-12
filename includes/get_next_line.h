/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_wolf.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdubray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 18:48:43 by mdubray           #+#    #+#             */
/*   Updated: 2015/01/16 16:40:28 by mdubray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

t_read				*ft_freeread(t_read *red, t_read *prev, t_read **start);
t_read				*ft_newread(int fd);
int					ft_print(int n, t_read **tab, t_read **s, char **l);
int					ft_findendl(int fd, t_read *red);
int					get_next_line(int fd, char **line);

#endif
