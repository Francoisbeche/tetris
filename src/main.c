/*
** main.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 14:53:02 2016 beche_f
** Last update Sun Mar 20 09:45:08 2016 bourre_a
*/
#include "my.h"

int	set_game(t_tetris *t, char *av)
{
  if ((t->list = load_tetrimino(t->list)) == NULL)
    return (-1);
  if ((init_struct_tetris(t, av)) == -1)
    return (-1);
  if (malloc_timer(t) == -1)
    return (-1);
  return (0);
}

int	play(t_tetris *tet)
{
  int	i;
  char	buffer[11];
  int	len;
  int	c;

  i = 0;
  while (i == 0)
    {
      create_map(tet);
      if ((c = game(tet)) == 2)
	return (0);
      my_putstr("\n\n\nGAME OVER !!\nPlay again? [y/n]\n");
      if ((len = read(0, buffer, 10)) == -1)
	return (0);
      if (buffer[0] == 'n')
	i = 1;
      else
	{
	  tet->recap.high_score = tet->recap.score;
	  tet->recap.score = 0;
	  tet->sec = 0;
	}
      my_memset(buffer, '\0', 10);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
   t_tetris	tet;

  tet.list = NULL;
  tet.env = my_get_env(&tet, env);
  if ((set_game(&tet, av[0])) == -1)
    return (-1);
  create_my_tab_fct(&tet);
  init_struct_tetris_2(&tet);
  if (ac > 1)
    {
      go_to_option(ac, av, &tet);
      if (tet.help == 1)
  	{
  	  my_aff_error_opt();
  	  return (0);
  	}
    }
  play(&tet);
  (void)av;
  free_list(tet.list);
  return (0);
}
