/*
** level.c for level in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Tue Feb 23 14:12:45 2016 bourre_a
** Last update Tue Feb 23 15:44:09 2016 bourre_a
*/

#include "my.h"

int	level(char *num, t_tetris	*tetris)
{
  int	my_num;
  int	i;

  i = 0;
  while (num[i] != '\0')
    {
      if ((num[i] < 48) || (num[i] > 57))
	{
	  if ((my_putstr("Error\n")) == -1)
	    return (-1);
	  return (-1);
	}
      i++;
    }
  my_num = my_getnbr(num);
  if (my_num <= 0)
    {
      if ((my_putstr("Error\n")) == -1)
	return (-1);
      return (-1);
    }
  tetris->level = my_num;
  return (0);
}
