/*
** get_next_tet.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/next
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Thu Mar 17 00:20:03 2016 beche_f
** Last update Thu Mar 17 00:20:39 2016 beche_f
*/

#include "my.h"

t_tetris	*gestion_next(t_tetris *t, int i)
{
  if (t->atm == NULL)
    {
      t->next = get_next_tet(t);
      t->atm = t->list->tail;
    }
  if (i == 0)
    {
      t->atm = t->next;
      t->next = get_next_tet(t);
  }
  return (t);
}
