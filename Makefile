# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdubray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/14 17:25:59 by mdubray           #+#    #+#              #
#    Updated: 2015/01/21 19:55:57 by mdubray          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/get_next_line.c src/key_p_r.c src/w_calcul.c src/w_check.c src/w_directions.c src/w_draw.c src/w_get_number.c src/w_menu.c src/w_save.c src/w_anim_arm.c src/w_settings.c src/w_manage_settings.c src/w_img.c src/w_draw_geometric.c src/w_straff.c src/w_check_wall.c src/wolf3d.c
HEAD = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = wolf3d

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L/usr/X11/lib -lmlx -lX11 -lXext -Llibft -lft -I $(HEAD)

clean:
	make -C libft/ clean

fclean:
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
