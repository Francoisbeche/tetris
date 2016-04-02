/*
** init_struct_tetris_2.c for  in /home/beche_f/PSU_2015_tetris/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sat Mar 19 14:09:55 2016 beche_f
** Last update Sat Mar 19 19:07:32 2016 beche_f
*/

#include "my.h"

int	init_struct_tetris_2(t_tetris *t)
{
  t->speed = 100000;
  t->is_pause = 0;
  t->pos = 1;
  t->atm = NULL;
  t->i = 0;
  t->recap.nb_line = 0;
  t->recap.score = 0;
  t->recap.high_score = 0;
  t->timestamp = time(NULL);
  return (0);
}
