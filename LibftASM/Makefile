CC			= nasm

NAME		= libfts.a

SRC			= 	ft_toupper.s ft_tolower.s ft_isalpha.s ft_isdigit.s ft_isalnum.s\
				ft_isascii.s ft_isprint.s ft_bzero.s ft_strcat.s ft_strlen.s\
				ft_puts.s ft_memcpy.s ft_memset.s ft_strdup.s ft_cat.s\
				ft_iscntrl.s ft_islower.s ft_ispunct.s ft_isspace.s\
				ft_isupper.s

OBJ			= $(SRC:.s=.o)

CFLAGS		= -f macho64

RM			= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

%.o:		%.s
			$(CC) $(CFLAGS) $< -o $@

.PHONY:		all clean re fclean

it:
			gcc -Wall -Werror -Wextra main.c -L. -lfts