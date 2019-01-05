##
## Makefile for Makefile in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
## 
## Made by Samuel
## Login   <samuel.rousseaux@epitech.eu>
## 
## Started on  Sun Dec 11 16:41:33 2016 Samuel
## Last update Fri Dec 16 04:12:57 2016 Samuel
##

SRCS=	./srcs/main.c       \
	./srcs/readmap.c    \
	./srcs/print.c      \
	./srcs/move_right.c \
        ./srcs/move_left.c  \
	./srcs/move_up.c    \
        ./srcs/move_down.c  \
	./srcs/list_o.c     \
	./srcs/list_x.c     \
	./srcs/victory.c    \
	./srcs/redim.c

OBJS=	$(SRCS:.c=.o)

CC=	gcc

CFLAGS=	-W -Wall -I./include/

NAME=	my_sokoban

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L./lib/ -lmy -lncurses

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: re flcean clean all
