/*
** print_in_next.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/next
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar 16 20:32:52 2016 beche_f
** Last update Sat Mar 19 16:54:33 2016 beche_f
*/

#include "my.h"

char	**print_in_next(t_tetris *t)
{
  int	y;
  int	x;

  y = 1;
  x = 1;
  while (t->next->map[y - 1] != NULL)
    {
      while (t->next->map[y - 1][x - 1] != 0)
	{
	  if (t->next->map[y - 1][x - 1] != ' ')
	    t->game.next[y][x] = t->next->color + 48;
	  x++;
	}
      x = 1;
      y++;
    }
  return (t->game.next);
}

char	**clean_next(t_tetris *t)
{
  int	y;
  int	x;

  x = 1;
  y = 1;
  while (t->game.next[y] != NULL)
    {
      while (t->game.next[y][x] != 0)
	{
	  if (t->game.next[y][x] >= '0' && t->game.next[y][x] <= '9')
	    t->game.next[y][x] = ' ';
	  x++;
	}
      x = 0;
      y++;
    }
  return (t->game.next);
}
