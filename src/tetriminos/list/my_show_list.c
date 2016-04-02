/*
** my_show_list.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 15:16:31 2016 beche_f
** Last update Sat Mar 19 17:14:23 2016 beche_f
*/

#include "my.h"

void	display_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i++;
    }
}
int	my_show_list(t_list *list)
{
  t_elem	*tmp;

  tmp = list->tail;
  while (tmp != NULL)
    {
      tmp = tmp->prev;
    }
  return (0);
}
