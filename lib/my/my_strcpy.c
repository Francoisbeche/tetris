/*
** my_strcat.c for  in /home/beche_f/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Feb 23 22:47:43 2016 beche_f
** Last update Wed Mar 16 14:15:18 2016 beche_f
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char *src, char *dest, int size)
{
  int   i;

  i = 0;
  if ((dest = malloc(sizeof(char) * size + 1)) == NULL)
    return (0);
  my_memset(dest, '\0', size);
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
