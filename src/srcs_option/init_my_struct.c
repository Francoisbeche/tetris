/*
** init_my_struct.c for init_my_struct in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris/PSU_2015_tetris/src/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Thu Mar  3 15:50:14 2016 bourre_a
** Last update Fri Mar  4 14:41:56 2016 bourre_a
*/

#include "my.h"

int	init_my_struct(char **av,  t_option *op, int ac)
{
  int   size;
  char  *str;

  str = av[op->i];
  size = my_strlen(str);
  if ((op->option_with_arg = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  op->option_with_arg = cp_src_in_dest(av[op->i], op->option_with_arg);
  if ((op->option = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  my_memset(op->option, '\0', size);
  op->option = cp_src_in_dest(av[op->i], op->option);
  op->option = my_option(op->option);
  op->ac = ac;
  return (0);
}
