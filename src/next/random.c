/*
** random.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/next
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar 16 20:24:29 2016 beche_f
** Last update Sat Mar 19 17:01:04 2016 beche_f
*/

#include "my.h"

int	my_random(int _imin, int _imax)
{
  return (_imin + (rand () % (_imax-_imin+1)));
}
