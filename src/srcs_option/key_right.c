/*
** key_right.c for key_right in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Tue Feb 23 15:49:30 2016 bourre_a
** Last update Fri Mar 18 15:45:05 2016 bourre_a
*/

#include "my.h"

int	key_right(char *key_char, t_tetris *tetris)
{
  if ((tcheck_posibility_char(tetris, key_char)) == -1)
    {
      tetris->help = 1;
      return (-1);
    }
  tetris->right = key_char;
  return (0);
}
