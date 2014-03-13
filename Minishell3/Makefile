# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afollin <afollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/27 16:00:42 by afollin           #+#    #+#              #
#    Updated: 2014/02/07 17:13:49 by afollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_minishell3

SRC			= main.c ft_env.c ft_chevron.c ft_big_cmd.c ft_cd.c\
			  ft_list_become_chtab.c ft_cut_copy_or_paste.c ft_historic.c\
			  is_key_change_line.c ft_len.c is_key_cut_paste.c is_key_copy.c\
			  is_key_fast_move.c fast_cursor_move.c is_key_arrow.c\
			  ft_print.c save_final_list.c ft_init_main.c\
			  ft_list_put_elem.c ft_list_del.c ft_putc.c is_key_del_or_enter.c
LIB			=./libft/libft.a

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C libft/
			gcc $(CFLAGS) -o $(NAME) $(LIB) $(SRC) -I./libft/includes -ltermcap

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

lbclean:
			make clean -C libft/

lbfclean:	
			make fclean -C libft/

lbre:
			make re -C libft/

%.o:		%.c
			gcc $(CFLAGS) -c $< -o $@ -I./libft/includes

.PHONY:		all clean re fclean
