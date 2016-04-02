/*
** delet_ligne.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/game
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Thu Mar 17 15:14:26 2016 beche_f
** Last update Sat Mar 19 18:49:21 2016 beche_f
*/

#include "my.h"

int	is_full_line(char *str)
{
  int	x;

  x = 0;
  while (str[x] != 0)
    {
      if (str[x] == ' ' || str[x] == '-')
	return (-1);
      x++;
    }
  return (0);
}

int	check_if_full_line(char **map)
{
  int	y;

  y = 1;
  while (map[y] != NULL)
    {
      if (is_full_line(map[y]) == 0)
	return (y);
      y++;
    }
  return (-1);
}

char	**delet_line(char **map, t_tetris *t)
{
  int	nb;

  if ((nb = check_if_full_line(map)) != -1)
    {
      while (nb > 0)
	{
	  my_memset(map[nb], 0, 10);
	  my_strcat(map[nb - 1], map[nb]);
	  my_memset(map[1], ' ', 10);
	  map[1][0] = '|';
	  map[1][9] = '|';
	  nb--;
	}
      t->recap.score = t->recap.score + 10;
      t->recap.nb_line++;
      delet_line(map, t);
    }
  return (map);
}
