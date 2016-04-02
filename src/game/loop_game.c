/*
** loop_game.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/game
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 20:44:55 2016 beche_f
** Last update Sat Mar 19 19:27:07 2016 beche_f
*/

#include "my.h"

char	**print_in_map(int pos, t_elem *elem, int i, t_tetris *t)
{
  int	y;
  int	x;
  int	yy;
  int	xx;

  y = 0;
  x = 0;
  yy = i;
  xx = pos;
  while (elem->map[y] != NULL)
    {
      while (elem->map[y][x] != 0)
	{
	  if (elem->map[y][x] != ' ')
	    t->game.game[yy][xx] = elem->color + 48;
	  x++;
	  xx++;
	}
      x = 0;
      xx = pos;
      y++;
      yy++;
    }
  return (t->game.game);
}

int	stop_tet(t_elem *elem, char **map, int i, int pos)
{
  int	y;
  int	x;
  int	save;

  save = 0;
  x = 0;
  y = 0;
  while (elem->map[0][x] != 0)
    {
      while (elem->map[y] != NULL)
	{
	  if (elem->map[y][x] == '*')
	    save = y;
	  y++;
	}
      y = 0;
      if (map[save + i][x + pos] != ' ')
	return (-1);
      x++;
    }
  return (0);
}

char	**maj_save(char **save, char **map)
{
  free_char_2d(save);
  if ((save = cpy_char_2d(map, save)) == NULL)
    exit(EXIT_FAILURE);
  return (save);
}

t_elem		*get_next_tet(t_tetris *t)
{
  t_elem	*tmp;
  int		i;
  int		rand;

  i = 0;
  time(NULL);
  tmp = t->list->tail;
  while (tmp != NULL)
    {
      if (tmp->status == 0)
	i++;
      tmp = tmp->prev;
    }
  rand = my_random(0,(i - 1));
  tmp = t->list->tail;
  i = 0;
  while (i < rand)
    {
      tmp = tmp->prev;
      if (tmp->status == 1)
	tmp = tmp->prev;
      i++;
    }
  return (tmp);
}

char		**loop_game(t_tetris *t, char **map)
{
  static char	**save = NULL;

  if (t->is_pause == 1)
    return (map);
  t = gestion_next(t, t->i);
  if (save == NULL)
    {
      if ((save = cpy_char_2d(map, save)) == NULL)
	return (NULL);
    }
  else
    maj_save(map, save);
  map = print_in_map(t->pos, t->atm, t->i++, t);
  if ((save = end_game(save)) == NULL)
    return (NULL);
  if (t->i == (t->map_size.height - 1) ||
      stop_tet(t->atm, map, t->i, t->pos) == - 1)
    {
      map = delet_line(map, t);
      maj_save(save, map);
      t->i = 0;
      t->pos = 1;
    }
  return (map);
}
