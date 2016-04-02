##
## Makefile for  in /home/beche_f/PSU_2015_tetris/fran
## 
## Made by beche_f
## Login   <beche_f@epitech.net>
## 
## Started on  Tue Feb 23 15:32:20 2016 beche_f
## Last update Wed Mar  9 21:49:34 2016 beche_f
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c				\
		load_tetrimino.c		\
		list/create_list.c		\
		list/free_list.c		\
		list/my_show_list.c		\
		list/put_in_list.c		\
		check/is_tetrimino_file.c	\
		check/is_file.c			\
		check/check_char.c		\
		../../lib/my/my_strcat.c	\
		../../lib/my/my_memset.c	\
		../../lib/my/get_next_line.c	\
		../../lib/my/my_getnbr.c	\
		../../lib/my/function.c		\
		get_tetrimino.c			\
		get_first_line.c		\
		set_tetrimino.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../../a.out

INCLUDE	=	-I./../../include/

FLAGS	=	-W -Werror -Wall -Wextra -ansi -pedantic

CFLAGS	=	$(INCLUDE) # $(FLAGS) -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
