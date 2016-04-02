/*
** my_memset.c for  in /home/beche_f/rendu/PSU_2015_minitalk/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Jan 29 19:14:30 2016 beche_f
** Last update Fri Mar  4 12:47:54 2016 bourre_a
*/

#include "my.h"

char	*my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      i++;
    }
  str[i] = 0;
  return (str);
}
