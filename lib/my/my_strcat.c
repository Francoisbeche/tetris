/*
** my_strcat.c for  in /home/beche_f/PSU_2015_tetris/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Feb 23 22:48:58 2016 beche_f
** Last update Sat Mar 19 17:13:19 2016 beche_f
*/
#include <stdlib.h>

char	*my_strcat(char *src, char *dest)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  if (dest == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      i++;
    }
  while (src[j] != 0)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  return (dest);
}
