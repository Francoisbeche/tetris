/*
** go_to_option.c for go_to_option in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Wed Feb 24 14:07:59 2016 bourre_a
** Last update Sat Mar 19 16:23:59 2016 bourre_a
*/

#include "my.h"

char	*cp_src_in_dest(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

int	finish_use_my_function(t_option *opt, int num, t_tetris *te, char **av)
{
  if ((num == 14) || (num == 19))
    opt->debug = 1;
  else if (num == 15)
    te->fct[15].fct(av[opt->i], te);
  else if (num == 16)
    {
      display_help(te);
      te->help = 1;
    }
  else if ((num == 17) || (num == 18))
    te->without_next = 0;
  return (0);
}

int	num_inf_14(t_option *opt, int num, t_tetris *te, char **av)
{
  if ((opt->arg = malloc(sizeof(char) * (opt->size + 1))) == NULL)
    return (-1);
  my_memset(opt->arg, '\0', opt->size);
  opt->arg = cp_src_in_dest(av[opt->i], opt->arg);
  if ((opt->arg = modif_my_str(opt->arg, te)) == NULL)
    return (-1);
  te->fct[num].fct(opt->arg, te);
  return (0);
}

int	use_my_function(t_option *opt, int num, t_tetris *te, char **av)
{
  opt->size = my_strlen(av[opt->i]);
  if (num < 7)
    {
      if ((opt->i + 1) >= opt->ac)
	return (-1);
      opt->next_arg = av[opt->i + 1];
      te->fct[num].fct(opt->next_arg, te);
      opt->i += 1;
    }
  else if (num < 14)
    {
      if ((num_inf_14(opt, num, te, av)) == -1)
	{
	  te->help = 1;
	  return (-1);
	}
    }
  else
    {
      if ((finish_use_my_function(opt, num, te, av)) == -1)
	return (-1);
    }
  free(opt->option);
  free(opt->option_with_arg);
  return (0);
}

int	go_to_option(int ac, char **av, t_tetris *tetris)
{
  t_option	option;
  char		**tab;

  tab = NULL;
  tab = my_tab_1(tab);
  option.debug = 0;
  option.i = 1;
  option.ac = ac;
  if ((tcheck_all_option(&option, av, tetris, tab))  == -1)
    {
      return (-1);
    }
  if (option.debug == 1)
    debug_mode(" ", tetris);
  free_my_char_star_star(tab);
  return (0);
}
