##
## Makefile for  in /home/beche_f/PSU_2015_tetris/fran
## 
## Made by beche_f
## Login   <beche_f@epitech.net>
## 
## Started on  Tue Feb 23 15:32:20 2016 beche_f
## Last update Sun Mar 20 14:52:52 2016 bourre_a
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	src/main.c					\
		src/tetriminos/get_tetrimino.c			\
		src/tetriminos/set_tetrimino.c			\
		src/tetriminos/get_first_line.c			\
		src/tetriminos/load_tetrimino.c			\
		src/tetriminos/check/is_file.c			\
		src/tetriminos/check/is_tetrimino_file.c	\
		src/tetriminos/list/create_list.c		\
		src/tetriminos/list/free_list.c			\
		src/tetriminos/list/my_show_list.c		\
		src/tetriminos/list/put_in_list.c		\
		src/map/create_map.c				\
		src/map/malloc_maps.c				\
		src/srcs_option/create_my_tab_fct.c		\
		src/srcs_option/go_to_option.c			\
		src/srcs_option/init_struct_tetris.c		\
		src/srcs_option/debug_mode.c			\
		src/srcs_option/debug_mode_2.c			\
		src/srcs_option/fill_map_size.c			\
		src/srcs_option/help.c				\
		src/srcs_option/key_drop.c			\
		src/srcs_option/key_left.c			\
		src/srcs_option/key_pause.c			\
		src/srcs_option/key_quit.c			\
		src/srcs_option/key_right.c			\
		src/srcs_option/key_turn.c			\
		src/srcs_option/level.c				\
		src/srcs_option/get_my_size.c			\
		src/srcs_option/modif_my_str.c			\
		src/srcs_option/tcheck_posibility_char.c	\
		src/srcs_option/my_option.c			\
		src/srcs_option/init_my_struct.c		\
		src/srcs_option/tcheck_all_option.c		\
		src/srcs_option/mode_canonique.c		\
		src/game.c					\
		src/timer/timer.c				\
		src/tetriminos/tri_file.c			\
		src/tetriminos/fill_sorted_file.c		\
		src/game/loop_game.c				\
		src/init_ncurses.c				\
		src/compar/compar.c				\
		src/arrow.c					\
		src/next/random.c				\
		src/next/print_in_next.c			\
		src/next/get_next_tet.c				\
		src/game/delet_ligne.c				\
		src/game/colision.c				\
		src/game/level.c				\
		src/init_struct_tetris_2.c			\
		src/my_get_env.c				\
		src/game/end_game.c

LIB	=	lib/my/function.c		\
		lib/my/my_getnbr.c		\
		lib/my/my_put_nbr.c		\
		lib/my/my_strcat.c		\
		lib/my/my_strcpy.c		\
		lib/my/get_next_line.c		\
		lib/my/my_memset.c		\
		lib/my/malloc_char_2d.c		\
		lib/my/display_char_2d.c	\
		lib/my/free_char_2d.c		\
		lib/my/cpy_char_2d.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	tetris

INCLUDE	=	-I./include/

CFLAGS	=	$(INCLUDE)  -W -Wall -Wextra -Werror -pedantic



$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
