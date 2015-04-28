# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afollin <afollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 15:11:39 by afollin           #+#    #+#              #
#    Updated: 2015/04/22 16:35:52 by afollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_minishell1
CFLAGS	= 	-Wall -Werror -Wextra
SRC		= 	add_rm_env.c cd_stuff.c env_stuff.c exec_stuff.c main.c \
			utilities.c utilities_bis.c

all:		$(NAME)

$(NAME):	$(SRC)
			make -C libft/
			gcc $(CFLAGS) $(SRC) -o $@ libft/libft.a -I libft/includes/ -I ./

fclean:
			rm -rf $(NAME)

clean:
			rm -rf $(NAME)
	
re:			fclean $(NAME)
