/*
** get_my_size.c for get_my_size in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/src/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Sun Mar 20 14:50:21 2016 bourre_a
** Last update Sun Mar 20 14:56:29 2016 bourre_a
*/

#include "my.h"

char	*get_my_size(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while ((str[i] != '=') && (str[i] != '\0'))
    i++;
  i++;
  if (str[i] == '\0')
    return (NULL);
  while (str[i] != '\0')
    {
      str[j] = str[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}
