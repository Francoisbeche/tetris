/*
** display_char_2d.c for  in /home/beche_f/testtetris/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 14:57:33 2016 beche_f
** Last update Fri Mar 11 14:58:19 2016 beche_f
*/

#include "lib.h"

void	display_char_2d(char **map)
{
  int	y;

  y = 0;
  while (map[y] != NULL)
    {
      my_putstr(map[y]);
      my_putchar('\n');
      y++;
    }
}
