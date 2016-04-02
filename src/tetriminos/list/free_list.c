/*
** free_list.c for  in /home/beche_f/sudoki-bi/src/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sun Feb 28 21:31:39 2016 beche_f
** Last update Mon Feb 29 16:14:27 2016 beche_f
*/

#include "my.h"

t_list		*delet_list(t_list *list)
{
  t_elem        *tmp;

  if (list->head == NULL)
    {
      free(list);
      return (0);
    }
  tmp = list->head;
  list->head = list->head->next;
  free(tmp);
  tmp = NULL;
  delet_list(list);
  return (0);
}

void		free_list(t_list *list)
{
  t_elem	*tmp;

  (void)tmp;
  tmp = list->tail;
  while (tmp != NULL)
    {
      free(tmp->file);
      free(tmp->path);
      tmp = tmp->prev;
    }
  delet_list(list);
}
