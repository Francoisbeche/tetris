/*
** fill_sorted_file.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 16:07:39 2016 beche_f
** Last update Sat Mar 19 17:06:31 2016 beche_f
*/

#include "my.h"

char	**extend_strcat(char **src, char **dest, int y)
{
  my_strcat(src[y], dest[y + 1]);
  my_strcat(src[y + 1], dest[y]);
  return (dest);
}
int	get_index_differ(char **src, char **dest, int y)
{
  int	j;

  (void)dest;
  j = 0;
  while (src[y][j] == src[y + 1][j])
    j++;
  return (j);
}
char	**fill_sorted_file(char **src, char **dest)
{
  int   y;
  int	j;

  y = 0;
  while (src[y] != NULL)
    {
      if (src[y + 1] != NULL)
	{
	  if (src[y][0] == src[y + 1][0])
	    {
	      j = get_index_differ(src, dest, y);
	      if (src[y][j] > src[y + 1][j])
		extend_strcat(src, dest, y++);
	      else
		my_strcat(src[y], dest[y]);
	    }
	  else
            my_strcat(src[y], dest[y]);
	}
      else
        my_strcat(src[y], dest[y]);
      y++;
    }
  return (dest);
}
