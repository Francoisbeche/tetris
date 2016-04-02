/*
** tetriminos.h for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 14:38:17 2016 beche_f
** Last update Fri Mar 11 16:05:37 2016 beche_f
*/

#ifndef TETRIMINOS_H_
#define TETRIMINOS_H_

typedef struct	s_elem
{
  int		status;
  char		*file;
  char		*path;
  char		**map;
  int		width;
  int		height;
  int		color;
  struct s_elem	*next;
  struct s_elem	*prev;
}		t_elem;

typedef struct	s_list
{
  t_elem	*head;
  t_elem	*tail;
  int		nb_file;
}		t_list;

t_list		*create_list(t_list*);
t_list		*load_tetrimino(t_list*);
int		put_in_list(t_list*, char*);
int		my_show_list(t_list*);
void		free_list(t_list*);
int		check_line_1(char*);
t_elem		*parse_line_1(t_elem*, char*);
t_elem		*malloc_tetriminos(t_elem*);
void		free_map(char**);
int		check_map(char**);
int		check_map_size(t_elem*);
#endif /* !TETRIMINOS_H_ */
