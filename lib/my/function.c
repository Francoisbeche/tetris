/*
** function.c for  in /home/beche_f/rendu/PSU_2015_minitalk/lib/my
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Jan 29 18:15:52 2016 beche_f
** Last update Tue Mar  1 00:27:18 2016 beche_f
*/

#include <unistd.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i++;
    }
  return (i);
}

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (-1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (my_putchar(str[i]) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int	my_puterror(char *str)
{
  int	i;

  i = my_strlen(str) + 1;
  if (write(2, str, i) == -1)
    return (-1);
  return (0);
}
