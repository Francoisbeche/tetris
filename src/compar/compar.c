/*
** compar.c for compar in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/src/compar
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Tue Mar 15 17:54:36 2016 bourre_a
** Last update Sat Mar 19 17:42:50 2016 beche_f
*/

#include "my.h"

int	compar_str(char *buffer, char *key)
{
  int	i;
  int	size;

  size = my_strlen(buffer);
  i = 0;
  while ((buffer[i] == key[i]) && (buffer[i] != '\0'))
    {
      i++;
    }
  if ((i == size) && (key[i] == '\0'))
    return (0);
  else
    return (-1);
}
