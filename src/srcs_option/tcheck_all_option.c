/*
** tcheck_all_option.c for tcheck_all_option in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris/PSU_2015_tetris/src/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Fri Mar  4 15:08:16 2016 bourre_a
** Last update Fri Mar 18 15:50:29 2016 bourre_a
*/

#include "my.h"

int	my_aff_error_opt()
{
  if ((my_putstr("./tetris : option invalid\n")) == -1)
    return (-1);
  if ((my_putstr("./tetris --help for more information\n")) == -1)
    return (-1);
  return (0);
}


int	tcheck_all_option(t_option *option, char **av, t_tetris *tetris, char **tab)
{
  while (option->i < option->ac)
    {
      if ((init_my_struct(av, option, option->ac)) == -1)
	{
	  tetris->help = 1;
	  return (-1);
	}
      if ((tcheck_with_tab(option->option, option, tab)) == -1)
        {
	  tetris->help = 1;
          return (-1);
        }
      if (option->numero >= 0)
	{
	  if ((use_my_function(option, option->numero, tetris, av)) == -1)
	    {
	      tetris->help = 1;
	      return (-1);
	    }
	}
      option->i++;
    }
  return (0);
}
