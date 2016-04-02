/*
** free_char_2d.c for  in /home/beche_f/testtetris/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 15:02:25 2016 beche_f
** Last update Sat Mar 19 19:30:00 2016 beche_f
*/

#include <stdlib.h>
#include "lib.h"

void	free_char_2d(char **map)
{
  int	y;

  y = 0;
  while (map[y] != NULL)
    {
      free(map[y]);
      y++;
    }
  free(map);
}
