/*
** is_file.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos/check
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 16:15:39 2016 beche_f
** Last update Sat Mar 19 17:14:00 2016 beche_f
*/

#include "my.h"

void	free_isnt_file(t_elem *elem, struct stat* s)
{
  free(s);
  free(elem->path);
  free(elem->file);
  free(elem);
}

int	is_file(t_elem *elem)
{
  struct stat *fichier;

  if ((fichier = malloc(sizeof(struct stat))) == NULL)
    return (-1);
  if (stat(elem->path, fichier) == -1)
    {
      return (-1);
    }
  if (S_ISDIR(fichier->st_mode) == 1)
    {
      return (-1);
    }
  if (fichier->st_size < 5)
    {
      return (-1);
    }
  free(fichier);
  return (0);
}
