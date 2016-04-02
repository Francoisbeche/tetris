/*
** modif_my_str.c for modif_my_str in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Mon Feb 29 16:44:13 2016 bourre_a
** Last update Sat Mar 19 16:28:02 2016 bourre_a
*/

#include "my.h"

char	*modif_my_str(char *str, t_tetris *t)
{
  int   i;
  int   j;
  int	size;

  size = my_strlen(str);
  i = 0;
  j = 0;
  while ((str[i] != '=') && (str[i] != '\0'))
    i++;
  i++;
  if (i == size)
    {
      t->help = 1;
      return (NULL);
    }
  i++;
  while (str[i] != '\0')
    str[j++] = str[i++];
  str[j] = '\0';
  return (str);
}
