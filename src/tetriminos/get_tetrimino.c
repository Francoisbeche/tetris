/*
** get_tetrimino.c for  in /home/beche_f/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar  9 20:34:24 2016 beche_f
** Last update Sat Mar 19 17:09:45 2016 beche_f
*/

#include "my.h"

t_list	*set_first_line(t_list *list)
{
  t_elem	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (tmp->status == 0)
	{
	  if (get_first_line(tmp) == -1)
	    {
	      tmp->status = 1;
	    }

	}
      tmp = tmp->next;
    }
  return (list);
}
t_list	*set_tetrimino(t_list *list)
{
  t_elem	*tmp;

  tmp = list->head;
  while (tmp != NULL)
    {
      if (tmp->status == 0)
	{
	  if (malloc_tetrimino(tmp) == 0)
	    {
	      if (recup_tetrimino(tmp, 0, 0, -1) == -1)
		tmp->status = 1;
	      if (check_carac(tmp->map) == -1)
		tmp->status = 1;
	      if (check_is_good_carac_w(tmp) == -1 || check_is_good_carac_h(tmp) == -1)
		tmp->status = 1;
	    }
	}
      tmp = tmp->next;
    }
  return (list);
}
t_list	*get_tetrimino(t_list *list)
{
  list = set_first_line(list);
  list = set_tetrimino(list);
  return (list);
}
