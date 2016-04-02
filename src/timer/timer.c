/*
** main.c for  in /home/beche_f/timer
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  8 14:10:23 2016 beche_f
** Last update Sat Mar 19 19:11:19 2016 beche_f
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

t_tetris	*get_hour(int sec, t_tetris *t)
{
  int		res;

  res = sec / 3600;
  t->timer[1] = res % 10 + 48;
  t->timer[0] = res / 10 + 48;
  return (t);
}

t_tetris	*get_min(int sec, t_tetris *t)
{
  int		res;

  res = sec % 3600;
  res = res / 60;
  t->timer[4] = res % 10 + 48;
  t->timer[3] = res / 10 + 48;
  return (t);
}

t_tetris	*get_sec(int sec, t_tetris *t)
{
  int		 res;

  res = sec % 3600;
  res = res % 60;
  t->timer[7] = res % 10 + 48;
  t->timer[6] = res / 10 + 48;
  return (t);
}

t_tetris	*timerr(t_tetris *t)
{
  static time_t timezer;

  timezer = time(NULL);
  if (timezer > t->timestamp)
    {
      t->sec++;
      t->timestamp = time(NULL);
      t->recap.score++;
    }
  t = get_sec(t->sec, t);
  t = get_min(t->sec, t);
  t = get_hour(t->sec, t);
  return (t);
}
