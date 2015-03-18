# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afollin <afollin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 15:11:39 by afollin           #+#    #+#              #
#    Updated: 2015/03/05 15:11:40 by afollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ls
CFLAGS	= 	-Wall -Werror -Wextra -Wno-unused
SRC		= 	main.c option_l.c sort_ascii.c option_a.c option_lil_t_lil_r.c \
			option_big_r.c prepare_field.c utilities.c compte_blocks.c \
			funct_ls.c get_elems_to_display.c

all:		$(NAME)

$(NAME):	$(SRC)
			gcc $(CFLAGS) $(SRC) -o $@ libft/libft.a -I libft/includes/ -I ./

fclean:
			rm -rf $(NAME)

clean:
			rm -rf $(NAME)
	
re:			fclean $(NAME)
