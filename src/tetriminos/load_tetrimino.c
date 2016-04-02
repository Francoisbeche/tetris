/*
** load_tetrimino.c for  in /home/beche_f/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  1 14:55:30 2016 beche_f
** Last update Sun Mar 20 10:26:46 2016 beche_f
*/

#include "my.h"

int	nb_file()
{
  DIR *d;
  struct dirent *e;
  int	i;

  i = 0;
  if ((d = opendir(PATH_TETRIMINOS)) ==  NULL)
    {
      return (-1);
    }
  while ((e = readdir(d)) != NULL)
    {
     if (is_tetrimino_file(e->d_name) == 0)
       {
	 i++;
       }
    }
  closedir(d);
  return (i);
}

t_list		*load_tetrimino_2(t_list *list, char **file_sort,
				  char **file_unsorted)
{
  int	i;

  i = 0;
  file_sort = tri_file(file_unsorted, file_sort);
  file_sort = get_only_name(file_sort);
  free_char_2d(file_unsorted);
  file_unsorted = malloc_char_2d(file_unsorted, 255, nb_file());
  file_unsorted = fill_sorted_file(file_sort, file_unsorted);
  file_unsorted = reverse_reset_char_2d(file_unsorted);
  while (file_unsorted[i] != NULL)
    put_in_list(list, file_unsorted[i++]);
  get_tetrimino(list);
  return (list);
}

t_list		*load_tetrimino(t_list *list)
{
  DIR *d;
  struct dirent *e;
  char	**file_unsorted;
  char	**file_sort;
  int	i;

  i = 0;
  file_sort = NULL;
  file_unsorted = NULL;
  if ((list = create_list(list)) == NULL)
    return (NULL);
  if ((d = opendir(PATH_TETRIMINOS)) ==  NULL)
    return (NULL);
  file_unsorted = malloc_char_2d(file_unsorted, 255, nb_file());
  file_sort = malloc_char_2d(file_sort, 255, nb_file());
  while ((e = readdir(d))!=NULL)
    if (is_tetrimino_file(e->d_name) == 0)
      my_strcat(e->d_name, file_unsorted[i++]);
  load_tetrimino_2(list, file_sort, file_unsorted);
  closedir(d);
  /* free_char_2d(file_sort); */
  /* free_char_2d(file_unsorted); */
  return (list);
}
