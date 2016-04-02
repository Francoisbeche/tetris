/*
** init_struct_tetris.c for  in /home/beche_f/PSU_2015_tetris/src/srcs_option
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  8 18:11:38 2016 beche_f
** Last update Sun Mar 20 09:45:34 2016 bourre_a
*/

#include "my.h"
#include <term.h>

int	malloc_timer(t_tetris *t)
{
  if ((t->timer = malloc(sizeof(char) * 9)) == NULL)
    return (-1);
  my_memset(t->timer, '0', 8);
  t->timer[2] = ':';
  t->timer[5] = ':';
  t->timer[8] = 0;
  return (0);
}

char	*init_char_star_struct(char *dest, char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((dest = malloc(sizeof(char) * 256)) == NULL)
    return (NULL);
  dest = my_memset(dest, '\0', 255);
  while (str[i] != '\0')
    {
      dest[j] = str[i];
      i++;
      j++;
    }
  return (dest);
}

int	init_real_struct(t_tetris *tetris, char *ptr)
{
  if ((tetris->left = init_char_star_struct(tetris->left,
					    (tigetstr("kcub1")))) == NULL)
    return (-1);
  if ((tetris->right = init_char_star_struct(tetris->right,
					     (tigetstr("kcuf1")))) == NULL)
    return (-1);
  if ((tetris->key_turn = init_char_star_struct(tetris->key_turn,
						(tigetstr("kcuu1")))) == NULL)
    return (-1);
  if ((tetris->key_drop = init_char_star_struct(tetris->key_drop,
						(tigetstr("kcud1")))) == NULL)
    return (-1);
  if ((tetris->key_quit = init_char_star_struct(tetris->key_quit, "q")) == NULL)
    return (-1);
  if ((tetris->key_pause = init_char_star_struct(tetris->key_pause, " ")) ==
      NULL)
	return (-1);
  if ((tetris->name_binari = init_char_star_struct(tetris->name_binari, ptr)) ==
      NULL)
	return (-1);
  tetris->map_size.width = 10;
  tetris->map_size.height = 20;
  tetris->without_next = 1;
  tetris->help = 0;
  return (0);
}

int	init_struct_tetris(t_tetris *tetris, char *ptr)
{
  char	*str;
  int	ret;
  int	i;

  (void)str;
  i = setupterm(tetris->env, 1, &ret);
  str = tigetstr("smkx");
  if (i == -1)
    return (-1);
  if (str != NULL)
    {
      tetris->level = 1;
      if ((init_real_struct(tetris, ptr)) == -1)
      	return (-1);
    }
  else
    return (-1);
  return (0);
}
