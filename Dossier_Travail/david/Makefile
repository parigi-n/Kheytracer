##
## Makefile for MAKEFILE in /home/vautie_a/rendu/MUL_2013 rtv1
## 
## Made by jules vautier
## Login   <vautie_a@epitech.net>
## 
## Started on  Mon Nov 17 15:13:58 3014 jules vautier
## Last update Sat Jun  6 21:17:52 2015 david sebaoun
##

SRC		= src/core/main.c \
		src/core/writer.c \
		src/core/command_line.c \
		src/core/gere_flag.c \
		src/core/gere_key_fct.c \
		src/core/check.c \
		src/core/parser.c \
		src/core/content_parsing.c \
		src/core/content_parsing_light.c \
		src/core/content_parsing_eye.c \
		src/core/parser_fct.c \
		src/core/parser_fct2.c \
		src/core/parser_fct_light.c \
		src/core/parser_fct_eye.c \
		src/core/splashscreen.c \
		src/cmd/load_file.c \
		src/cmd/object_creator.c \
		src/cmd/clear.c \
		src/cmd/render.c \
		src/cmd/help.c \
		src/cmd/my_exit.c \
		src/cmd/show_object_info.c \
		src/cmd/ls.c \
		src/raytracer/shadow.c \
		src/raytracer/rotate.c \
                src/raytracer/init_vec_rotate.c \
		src/raytracer/calc.c \
		src/raytracer/intensity_main.c \
		src/raytracer/intensity_object.c \
		src/raytracer/inter_cone.c \
		src/raytracer/inter_disc.c \
		src/raytracer/get_triangle_info.c \
		src/raytracer/triangle_tools.c \
		src/raytracer/inter_triangle.c \
		src/raytracer/inter_cylindre.c \
		src/raytracer/inter_sphere.c \
		src/raytracer/inter_plan.c \
		src/raytracer/my_pixel_put.c \
		src/raytracer/my_loading.c \
		src/raytracer/raytrace.c \
                src/lib/list/list_obj.c \
                src/lib/list/list_vec.c \
                src/lib/list/my_getlist.c \
                src/lib/list/fct_list_obj.c \
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
                src/lib/shared/strlcpy_mlx_substitute.c \
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
                src/lib/shared/decal.c

OBJ		= $(SRC:.c=.o)

NAME		= rt

CFLAGS		+= -Wextra -Wall
CFLAGS		+= -ansi -pedantic -g
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
