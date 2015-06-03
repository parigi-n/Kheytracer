##
## Makefile for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david/src/scene_creator
## 
## Made by david sebaoun
## Login   <sebaou_d@epitech.net>
## 
## Started on  Mon Jun  1 17:06:04 2015 david sebaoun
## Last update Tue Jun  2 12:28:12 2015 david sebaoun
##

CC = gcc

RM = rm -f

CFLAGS += -Wextra -Wall
CFLAGS += -ansi -pedantic
CFLAGS += -I./include

LDFLAGS = -lpanel -lncurses

NAME = scene_creator

SRCS =	src/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
