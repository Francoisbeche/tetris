/*
** my_get_env.c for  in /home/beche_f/PSU_2015_tetris/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sat Mar 19 16:21:05 2016 beche_f
** Last update Sat Mar 19 16:46:42 2016 beche_f
*/

#include "my.h"
int	search_for_env(char *str)
{
  int	i;
  char	term[6];

  term[0] = 'T' ;
  term[1] = 'E';
  term[2] = 'R';
  term[3] = 'M';
  term[4] = '=';
  term[5] = 0;
  i = 0;
  while ((str[i] != 0) && (term[i] != 0))
    {
      if (str[i] != term[i])
	return (-1);
      i++;
    }
  return (0);
}

char	*get_term(char *str, char *env)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (str[i] != '=')
    i++;
  i++;
  while (str[i] != 0)
    {
      env[a] = str[i];
      i++;
      a++;
    }
  return (env);
}

char	*my_get_env(t_tetris *t, char **env)
{
  int	y;

  y = 0;
  if ((t->env = malloc(255)) == NULL)
    exit(0);
  my_memset(t->env, '\0', 254);
  while (env[y] != NULL)
    {
      if (search_for_env(env[y]) == 0)
	{
	  t->env = get_term(env[y], t->env);
	}
      y++;
    }
  return (t->env);
}
