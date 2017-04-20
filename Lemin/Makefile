# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afollin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 17:30:21 by afollin           #+#    #+#              #
#    Updated: 2016/03/07 17:30:22 by afollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			attention a bien virer le -g
GCC =		gcc -Wall -Werror -Wextra -g
NAME =		lem-in
SRC =		main.c algo/do_lemin_algo.c parsing/step_get_nb_ant.c \
			parsing/is_comment_or_command.c utilities.c utilities2.c \
			parsing/step_get_cells.c parsing/step_get_tubes.c \
			algo/set_nighs_cells.c algo/get_paths.c algo/get_final_paths.c \
			print_walk.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

lem-in:		$(OBJ)
			make -C libft
			$(GCC) -Ilibft/includes/ -I. -o lem-in $(OBJ) libft/libft.a

main.o:		lemin.h

%.o:		%.c
			$(GCC) -Ilibft/includes/ -I. -o $@ -c $<

.PHONY:		clean fclean re

clean:
			rm -rf $(OBJ)
			make clean -C libft/

fclean:
			rm -rf $(OBJ)
			rm -rf $(NAME)
			make fclean -C libft/

re:			fclean $(NAME)
