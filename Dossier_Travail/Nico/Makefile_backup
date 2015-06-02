##
## Makefile for MAKEFILE in /home/vautie_a/rendu/MUL_2013 rtv1
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Nov 17 15:13:58 3014 jules vautier
## Last update Tue Jun  2 11:46:10 2015 Nicolas PARIGI
##

SRC		= src/executable/gere_flag.c \
		src/executable/gere_key_fct.c \
		src/executable/check.c \
                src/executable/tmp_load.c \
                src/executable/init_vec_rotate.c \
                src/lib/list/list.c \
                src/lib/list/my_getlist.c \
                src/lib/list/fct_list.c \
                src/lib/printf/mainprintf.c \
                src/lib/printf/fct_printf.c \
                src/lib/printf/printf_error.c \
                src/lib/wordtab/my_show_tab.c \
                src/lib/wordtab/fct_tab.c \
                src/lib/wordtab/my_word_to_tab.c \
                src/lib/wordtab/my_word_to_tab_custom.c \
                src/lib/wordtab/epur_str.c \
                src/lib/wordtab/tabcpy.c \
                src/lib/wordtab/freetab.c \
                src/lib/shared/fct_char.c \
                src/lib/shared/get_next_line.c \
                src/lib/shared/puterr.c \
                src/lib/shared/my_putchar.c \
                src/lib/shared/my_putstr.c \
                src/lib/shared/check_quote.c \
                src/lib/shared/my_putnbr.c \
                src/lib/shared/my_strlen.c \
                src/lib/shared/strcmp.c \
                src/lib/shared/my_getnbr.c \
                src/lib/shared/strcat.c \
								src/lib/shared/strcpy.c \
								src/lib/shared/decal.c \
		strlcpy_mlx_substitute.c \
		parser.c

OBJ		= $(SRC:.c=.o)

NAME		= rtv1

CFLAGS          += -ansi -pedantic -g
CFLAGS		+= -I./include

LDFLAGS		=

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) -L/usr/lib64 -Lminilibx -L/usr/lib64/X11 -lXext -lX11 -lmlx -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
