/*
** debug_mode_2.c for debug_mode_2 in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/src/srcs_option
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Sun Mar 13 13:56:54 2016 bourre_a
** Last update Fri Mar 18 17:45:39 2016 bourre_a
*/

#include "my.h"

int	display_debug(char *str)
{
  int   i;

  i = 0;
  if ((my_strlen(str)) == 1)
    {
      if ((my_putchar_debug(str[0])) == -1)
        return (-1);
    }
  else
    {
      while (str[i] != '\0')
        {
	  if (str[i] == 27)
	    {
	      if ((write(1, "^E", 2)) == -1)
	  	return (-1);
	      i++;
	    }
	  if ((write(1, &str[i], 1)) == -1)
	    return (-1);
          i++;
        }
    }
  return (0);
}

int	display_name(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '.')
    {
      if ((write(1, &str[i], 1)) == -1)
        return (-1);
      i++;
    }
  return (0);
}

int	my_putchar_debug(char c)
{
  if (c == 32)
    {
      if ((write(1, "(space)", 7)) == -1)
	return (-1);
    }
  else if (c == 27)
    {
      if ((write(1, "^E", 2)) == -1)
        return (-1);
    }
  else
    {
      if ((write(1, &c, 1)) == -1)
        return (-1);
    }
  return (0);
}

int	finish_debug_mode()
{
  char  buff[10];

  my_putstr("Press a key to start Tetris\n");
  mode(2);
  read(0, buff, 10);
  mode(1);
  return (0);
}
