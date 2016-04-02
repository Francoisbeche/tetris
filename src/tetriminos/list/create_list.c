/*
** create_list.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 15:04:44 2016 beche_f
** Last update Mon Feb 29 15:06:30 2016 beche_f
*/

#include "my.h"

t_list	*create_list(t_list *list)
{
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->head = NULL;
  list->tail = NULL;
  list->nb_file = 0;
  return (list);
}
