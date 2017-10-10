##
## Makefile for  in /home/girard_z/EPITECH_Y02/B-PSU-356/PSU_2016_malloc
##
## Made by girard_z
## Login   <girard_z@epitech.net>
##
## Started on  Sat Feb 11 12:57:07 2017 girard_z
## Last update Sat Feb 11 12:57:13 2017 girard_z
##

SRC		=	malloc.c	\
	  		free.c		\
	  		realloc.c	\
			calloc.c	\
			thread.c

OBJS		=	$(SRC:.c=.o)

NAME		=	libmy_malloc.so

CFLAGS		+=	-fpic -W -Wall -Wextra -Werror

LDFLAGS		+=	-shared

RM		=	rm -f

CC		=	gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(LDFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
