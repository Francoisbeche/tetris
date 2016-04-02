/*
** malloc_char_2d.c for  in /home/beche_f/testtetris/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 14:53:23 2016 beche_f
** Last update Fri Mar 11 15:00:00 2016 beche_f
*/

#include <stdlib.h>
#include "lib.h"

char	**malloc_char_2d(char **map, int w, int h)
{
  int	y;

  y = 0;
  if (( map = malloc(sizeof(char*) * (h + 1))) == NULL)
    return (NULL);
  map[h] = NULL;
  while (y < h)
    {
      if (( map[y] = malloc(sizeof(char) * (w + 1))) == NULL)
	return (NULL);
      my_memset(map[y], '\0', w);
      y++;
    }
  return (map);
}
