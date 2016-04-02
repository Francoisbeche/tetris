/*
** colision.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/game
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 18 14:03:53 2016 beche_f
** Last update Sat Mar 19 16:58:15 2016 beche_f
*/

#include "my.h"
int	get_pos_first_star(char *str)
{
  int	x;

  x = 0;
  while (str[x] != 0)
    {
      if (str[x] == '*')
	{
	  return (x);
	}
      x++;
    }
  return (-1);
}

int	colision_left(t_tetris *t)
{
  int	y;
  int	elem_pos;

  elem_pos = -1;
  y = 0;
  while (t->atm->map[y] != NULL)
    {
      if ((elem_pos  = get_pos_first_star(t->atm->map[y])) != -1)
	{
	  if (t->game.game[t->i + y][t->pos + elem_pos - 1] >= '0' &&
	      t->game.game[t->i + y][t->pos + elem_pos - 1] <= '9')
	    return (-1);
	}

      y++;
    }
  return (0);
}
