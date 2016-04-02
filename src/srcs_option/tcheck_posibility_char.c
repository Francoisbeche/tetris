/*
** tcheck_posibiity_char.c for tcheck_posibility_char in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Tue Feb 23 16:28:01 2016 bourre_a
** Last update Fri Mar 18 17:51:57 2016 bourre_a
*/

#include "my.h"

int	tcheck_the_char_star(char *str, char *c)
{
  int	i;
  int	j;
  int	size;

  i = 0;
  j = 0;
  size = my_strlen(str) + 1;
  while (c[i] == str[j])
    {
      i++;
      j++;
    }
  if (j == size)
    return (-1);
  return (0);
}

int	tcheck_posibility_char(t_tetris *tetris, char *c)
{
  if ((tcheck_the_char_star(tetris->left, c)) == -1)
    return (-1);
  if ((tcheck_the_char_star(tetris->right, c)) == -1)
    return (-1);
  if ((tcheck_the_char_star(tetris->key_turn, c)) == -1)
    return (-1);
  if ((tcheck_the_char_star(tetris->key_drop, c)) == -1)
    return (-1);
  if ((tcheck_the_char_star(tetris->key_quit, c)) == -1)
    return (-1);
  if ((tcheck_the_char_star(tetris->key_pause, c)) == -1)
    return (-1);
  return (0);
}
