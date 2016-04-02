/*
** put_in_list.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos/list
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 15:11:22 2016 beche_f
** Last update Wed Mar  9 20:24:32 2016 beche_f
*/

#include "my.h"
void	free_elem(t_elem *elem)
{
  free(elem->path);
  free(elem->file);
  free(elem);
}

t_elem	*get_path_name(t_elem *elem, char *file)
{
  int	i;

  i = 0;
  while (file[i] != 0)
    i++;
  if ((elem->file = malloc(sizeof(char)* (i + 1))) == NULL)
    return (NULL);
  my_memset(elem->file, '\0', i);
  elem->file = my_strcat(file, elem->file);
  if ((elem->path = malloc(sizeof(char)* (i + 18))) == NULL)
    return (NULL);
  my_memset(elem->path, '\0', (i + 17));
  elem->path = my_strcat(PATH_TETRIMINOS, elem->path);
  elem->path = my_strcat(file, elem->path);
  return (elem);
}
int	put_in_list(t_list *list, char *file)
{
  t_elem	*elem;

  if ((elem = malloc(sizeof(t_elem))) == NULL)
    return (-1);
  elem->status = 0;
  if ((elem = get_path_name(elem, file)) == NULL)
    return (-1);
  if (is_file(elem) == -1)
    elem->status = 1;
  elem->prev = NULL;
  if (list->head != NULL)
    {
      list->head->prev = elem;
      elem->next = list->head;
      list->head = elem;
    }
  else
    {
      list->head = elem;
      elem->next = NULL;
      list->tail = elem;
    }
  list->nb_file++;
  return (0);
}
