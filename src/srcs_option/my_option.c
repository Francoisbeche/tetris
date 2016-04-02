/*
** my_option.c for my_option in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris/PSU_2015_tetris/src/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Thu Mar  3 15:49:35 2016 bourre_a
** Last update Thu Mar  3 15:49:58 2016 bourre_a
*/

#include "my.h"

char	*my_option(char *str)
{
  char  *tmp;
  int   size;
  int   i;

  i = 0;
  size = my_strlen(str);
  tmp = NULL;
  if ((tmp = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  my_memset(tmp, '\0', size);
  while ((str[i] != '=') && (str[i] != '\0'))
    {
      tmp[i] = str[i];
      i++;
    }
  i = 0;
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i++;
    }
  str[i] = 0;
  free(tmp);
  return (str);
}
