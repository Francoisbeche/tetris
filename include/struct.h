/*
** struct.h for  in /home/beche_f/PSU_2015_tetris/include
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  8 18:09:42 2016 beche_f
** Last update Sun Mar 20 14:52:09 2016 bourre_a
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include "option.h"
#include "tetriminos.h"

typedef struct s_recap
{
  int		nb_line;
  int		level;
  int		high_score;
  int		score;
}		t_recap;

typedef struct	s_game
{
  int		next_piece;
  char		**game;
  char		**next;
  char		**score;
}		t_game;

typedef struct	s_map_size
{
  int		width;
  int		height;
}		t_map_size;

typedef struct		s_tetris
{
  int	sec;
  time_t		timestamp;
  int			i;
  int			is_pause;
  t_elem		*next;
  char			*env;
  t_elem		*atm;
  int			pos;
  unsigned int		speed;
  char			*name_binari;
  char			*timer;
  int			level;
  char			*left;
  char			*right;
  char			*key_turn;
  char			*key_drop;
  char			*key_quit;
  char			*key_pause;
  t_map_size		map_size;
  int			without_next;
  int			help;
  t_list		*list;
  struct s_fct		*fct;
  t_game		game;
  t_recap		recap;
}			t_tetris;

typedef struct	s_fct
{
 int		(*fct)(char*, t_tetris*);
}		t_fct;

char		**cpy_char_2d(char**, char**);
void		display_char_2d(char**);
void		free_char_2d(char**);
int		my_strlen(char*);
int		my_putchar(char);
int		my_putstr(char*);
int		my_puterror(char*);
char		*my_realloc(char*, int, char*);
int		is_b_slash_n(char*);
char		*maj_buffer(char*);
char		*xbuffer(char*, char*);
char		*get_next_line(int);
char		**malloc_char_2d(char**, int, int);
int		my_getnbr(char*);
char		*my_memset(char*, char, int);
int		my_put_nbr(int);
char		*my_strcat(char*, char*);
char		*my_strcpy(char*, char*, int);

char		**end_game(char**);
char		**print_in_map(int, t_elem*, int, t_tetris*);
int		check_for_stop_tet(t_elem*, char**, int, int);
char		**loop_game(t_tetris*, char**);

int		create_map(t_tetris*);
char		**malloc_maps(char**, int, int);
void		display_game_map(char**);
void		free_t_game(t_game*);
char		**fill_top(char**, int, int);
char		**fill_border(char**, int, int);

int		get_first_line(t_elem*);
int		malloc_tetrimino(t_elem*);
int		check_carac(char**);
int		check_is_good_carac_w(t_elem*);
int		check_is_good_carac_h(t_elem*);
int		recup_tetrimino(t_elem*, int, int, int);
int		is_tetrimino_file(char*);
t_list		*get_tetrimino(t_list*);
void		free_isnt_file(t_elem*, struct stat*);
t_list		*create_list(t_list*);
t_list		*delet_list(t_list*);
void		free_list(t_list*);
void		display_map(char**);
int		my_show_list(t_list*);
void		free_elem(t_elem*);
t_elem		*get_path_name(t_elem*, char*);
int		put_in_lis(t_list*, char*);
char		**extend_strcat(char**, char**, int);
int		get_index_differ(char**, char**, int);
char		**fill_sorted_file(char**, char**);
t_elem		*get_size(t_elem*, char*, int);
t_elem		*get_color(t_elem*, char*);
char		*clean_str(char*);
int		get_nb_carac(char*);
int		get_first_line(t_elem*);
t_list		*set_first_line(t_list*);
t_list		*set_tetrimino(t_list*);
int		nb_file();
t_list		*load_tetrimino_2(t_list*, char**, char**);
t_list		*load_tetrimino(t_list*);
int		is_file(t_elem*);
char		**reverse_reset_char_2d(char**);
char		**get_only_name(char**);
char		**reset_char_2d(char**);
char		**tri_file(char**, char**);

t_tetris	*timerr(t_tetris*);

int		create_my_tab_fct(t_tetris*);
char		**my_tab_1(char**);
void		free_my_char_star_star(char**);
int		tcheck_option(int, char**);
int		tcheck_with_tab(char*, t_option*, char**);
int		my_putchar_debug(char);
int		debug_mode_2(t_tetris*);
int		debug_mode_1(t_tetris*);
int		debug_mode(char*, t_tetris*);
int		my_strlen_map(char*);
char		*fill_number_1(char*, int, char*);
char		*fill_number_2(char*, int, int,  char*);
int		return_tetris(char*, char*, t_tetris*);
int		fill_map_size(char*, t_tetris*);
char		*my_option(char*);
int		init_my_struct(char**, t_option*, int);
char		*cp_src_in_dest(char*, char*);
void		finish_my_function(t_option*, int, t_tetris*, char**);
int		use_my_function(t_option*, int, t_tetris*, char**);
int		go_to_option(int, char**, t_tetris*);
int		finish_display();
int		display_help(t_tetris*);
int		init_struct_tetris(t_tetris *, char*);
int		key_drop(char*, t_tetris*);
int		key_left(char*, t_tetris*);
int		key_pause(char*, t_tetris*);
int		key_quit(char*, t_tetris*);
int		key_right(char*, t_tetris*);
int		key_turn(char*, t_tetris*);
int		level(char*, t_tetris*);
char		*modif_my_str(char*, t_tetris*);
int		tcheck_posibility_char(t_tetris*, char*);
int		my_aff_error();
int		tcheck_all_option(t_option*, char**, t_tetris*, char**);
int		malloc_timer(t_tetris*);
int		display_debug(char*);
int		display_name(char*);
int		my_putchar_debug(char);
int		finish_debug_mode();
int		mode(int);
char		*modif_my_key_str(char*);
int		compar_str(char *, char*);
void		init_ncurses();
int		my_aff_error_opt();
char		*get_my_size(char*);

char		**print_in_next(t_tetris*);
char		**clean_next(t_tetris*);
int		my_random(int, int);
t_tetris	*gestion_next(t_tetris*, int);
t_elem		*get_next_tet(t_tetris*);

char		**delet_line(char**, t_tetris*);

char		*my_get_env(t_tetris*, char**);
int		init_struct_tetris_2(t_tetris*);
int		get_level(int);
int		colision_left(t_tetris*);
#endif
