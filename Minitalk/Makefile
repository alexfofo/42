# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 01:26:11 by rcherik           #+#    #+#              #
#    Updated: 2014/02/09 14:35:21 by afollin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -c
RM=rm -rf

NAME_SERV=serveur
NAME=client

SRCS_CLT=client.c\
		 ft_utilities_c.c\
		 ft_error.c\
		 ft_putswag.c\

SRCS_SERV=serv.c\
		  ft_utilities_s.c\
		  ft_putswag.c\
		  ft_error.c\
		  ft_strjoin_c.c\
		  ft_strnew.c\
		  ft_strcpy.c\
		  ft_memcpy.c\
		  ft_strcmp.c\

OBJS_CLT=$(subst .c,.o,$(SRCS_CLT))
OBJS_SERV=$(subst .c,.o,$(SRCS_SERV))

all: $(NAME_SERV) $(NAME)

$(NAME_SERV): $(OBJS_SERV)
	$(CC) $(CFLAGS) $(SRCS_SERV) ; $(CC) $(OBJS_SERV) -o $(NAME_SERV)

$(NAME): $(OBJS_CLT)
	$(CC) $(CFLAGS) $(SRCS_CLT) ; $(CC) $(OBJS_CLT) -o $(NAME)

clean:
	$(RM) $(OBJS_SERV) $(OBJS_CLT)

fclean: clean
	$(RM) $(NAME_SERV) $(NAME)

re: fclean all

.PHONY: all clean fclean re
