/*
** create_my_tab_fct.c for create_my_tab_fct in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Wed Feb 24 11:22:44 2016 bourre_a
** Last update Sat Mar 12 11:07:47 2016 bourre_a
*/

#include "my.h"

int	create_my_tab_fct(t_tetris *tetris)
{
  if ((tetris->fct = malloc(sizeof(t_fct) * 17)) == NULL)
    return (-1);
  tetris->fct[0].fct = &(key_drop);
  tetris->fct[1].fct = &(key_left);
  tetris->fct[2].fct = &(key_pause);
  tetris->fct[3].fct = &(key_quit);
  tetris->fct[4].fct = &(key_right);
  tetris->fct[5].fct = &(key_turn);
  tetris->fct[6].fct = &(level);
  tetris->fct[7].fct = &(key_drop);
  tetris->fct[8].fct = &(key_left);
  tetris->fct[9].fct = &(key_pause);
  tetris->fct[10].fct = &(key_quit);
  tetris->fct[11].fct = &(key_right);
  tetris->fct[12].fct = &(key_turn);
  tetris->fct[13].fct = &(level);
  tetris->fct[14].fct = &(debug_mode);
  tetris->fct[15].fct = &(fill_map_size);
  tetris->fct[16].fct = NULL;
  return (0);
}

char	**my_tab_1(char **tab)
{
  if ((tab = malloc(sizeof(char *) * 21)) == NULL)
    return (NULL);
  tab[20] = NULL;
  tab[0] = my_strcpy("-kd", tab[0], 4);
  tab[1] = my_strcpy("-kl", tab[1], 4);
  tab[2] = my_strcpy("-kp", tab[2], 4);
  tab[3] = my_strcpy("-kq", tab[3], 4);
  tab[4] = my_strcpy("-kr", tab[4], 4);
  tab[5] = my_strcpy("-kt", tab[5], 4);
  tab[6] = my_strcpy("-l", tab[6], 3);
  tab[7] = my_strcpy("--key-drop", tab[7], 10);
  tab[8] = my_strcpy("--key-left", tab[8], 10);
  tab[9] = my_strcpy("--key-pause", tab[9], 11);
  tab[10] = my_strcpy("--key-quit", tab[10], 11);
  tab[11] = my_strcpy("--key-right", tab[11], 12);
  tab[12] = my_strcpy("--key-turn", tab[12], 11);
  tab[13] = my_strcpy("--level", tab[13], 8);
  tab[14] = my_strcpy("-d", tab[14], 3);
  tab[15] = my_strcpy("--map-size", tab[15],11);
  tab[16] = my_strcpy("--help", tab[16],7);
  tab[17] = my_strcpy("-w", tab[17],3);
  tab[18] = my_strcpy("--without-next", tab[18],15);
  tab[19] = my_strcpy("--debug", tab[19],8);
  return (tab);
}

void	free_my_char_star_star(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      free(str[i]);
      i++;
    }
  free(str);
}

int	tcheck_option(int ac, char **av)
{
  int   i;

  i = 1;
  while (i < ac)
    {
      if (av[i][0] != '-')
        return (-1);
      i++;
    }
  return (0);
}

int	tcheck_with_tab(char *my_option, t_option *option, char **tab)
{
  int   i;
  int   j;
  int   k;
  int   stop;

  i = 0;
  stop = 0;
  j = 0;
  k = 0;
  while (tab[i] != NULL)
    {
      while ((tab[i][j] != '\0') && (stop == 0))
        if (tab[i][j++] != my_option[k++])
          stop = 1;
      if ((stop == 0) && (my_option[k] == '\0'))
	{
	  option->numero = i;
	  return (0);
	}
      stop = 0;
      j = 0;
      k = 0;
      i++;
    }
  return (-1);
}
