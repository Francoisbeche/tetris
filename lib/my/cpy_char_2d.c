/*
** cpy_char_2d.c for  in /home/beche_f/testtetris/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 20:55:48 2016 beche_f
** Last update Wed Mar 16 14:08:36 2016 beche_f
*/

#include "lib.h"
#include "my.h"

char	**cpy_char_2d(char **src, char **dest)
{
  int	y;
  int	w;
  int	h;

  y = 0;
  w = my_strlen(src[0]);
  while (src[y] != NULL)
    y++;
  h = y;
  y = 0;
  if ((dest = malloc_char_2d(dest, w, h)) == NULL)
    return (NULL);
  while (src[y] != NULL)
    {
      my_strcat(src[y], dest[y]);
      y++;
    }
  return (dest);
}
