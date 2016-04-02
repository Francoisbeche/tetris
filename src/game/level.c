/*
** level.c for  in /home/beche_f/PSU_2015_tetris/src/game
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 18 17:51:42 2016 beche_f
** Last update Fri Mar 18 17:55:32 2016 beche_f
*/

#include "my.h"

int	get_level(int i)
{
  int	x;

  x = 0;
  while ((i / 10) > 0)
    {
      i = i / 10;
      x++;
    }
  return (x);
}
