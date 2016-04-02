/*
** debug_mode.c for debug_mode in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Wed Feb 24 11:43:26 2016 bourre_a
** Last update Fri Mar 18 17:47:10 2016 bourre_a
*/

#include "my.h"

int	display_tetri(t_elem *tmp)
{
  if ((display_name(tmp->file)) == -1)
    return (-1);
  if (tmp->status == 0)
    {
      if ((display_debug(" : Size ")) == -1)
	return (-1);
      if ((my_put_nbr(tmp->width)) == -1)
	return (-1);
      if ((display_debug("*")) == -1)
	return (-1);
      if ((my_put_nbr(tmp->height)) == -1)
	return (-1);
      if ((display_debug(" : Color ")) == -1)
	return (-1);
      if ((my_put_nbr(tmp->color)) == -1)
	return (-1);
      if ((display_debug(" :")) == -1)
	return (-1);
      if ((display_debug("\n")) == -1)
	return (-1);
      display_map(tmp->map);
    }
  else
    my_putstr(" : Error\n");
  return (0);
}

int	debug_mode_3(t_tetris *tetris)
{
  t_elem	*tmp;

 tmp = tetris->list->tail;
  while (tmp != NULL)
    {
      if ((display_debug("Tetriminos : Name ")) == -1)
	return (-1);
      if ((display_tetri(tmp)) == -1)
	return (-1);
      tmp = tmp->prev;
    }
  finish_debug_mode();
  return (0);
}

int	debug_mode_2(t_tetris *tetris)
{
  if ((my_putstr("\nLevel : ")) == -1)
    return (-1);
  if ((my_put_nbr(tetris->level)) == -1)
    return (-1);
  if ((my_putstr("\nSize : ")) == -1)
    return (-1);
  if ((my_put_nbr(tetris->map_size.height)) == -1)
    return (-1);
  if ((display_debug("*")) == -1)
    return (-1);
  if ((my_put_nbr(tetris->map_size.width)) == -1)
    return (-1);
 if ((my_putstr("\nTetriminos : ")) == -1)
    return (-1);
  if ((my_put_nbr(tetris->list->nb_file)) == -1)
    return (-1);
  if ((display_debug("\n")) == -1)
    return (-1);
  if ((debug_mode_3(tetris)) == -1)
    return (-1);
  return (0);
}

int	debug_mode_1(t_tetris *tetris)
{
  if ((display_debug(tetris->key_quit)) == -1)
    return (-1);
 if ((my_putstr("\nKey Pause : ")) == -1)
    return (-1);
 if ((display_debug(tetris->key_pause)) == -1)
   return (-1);
 if ((my_putstr("\nNext : ")) == -1)
   return (-1);
  if (tetris->without_next == 0)
    {
      if ((display_debug("No")) == -1)
	return (-1);
    }
  else
    {
      if ((display_debug("Yes")) == -1)
	return (-1);
    }
  return (debug_mode_2(tetris));
}

int	debug_mode(char *num, t_tetris *tetris)
{
  (void)num;
  if ((my_putstr("*** DEBUG MODE ***\nKey Left : ")) == -1)
    return (-1);
  if ((display_debug(tetris->left)) == -1)
    return (-1);
  if ((my_putstr("\nKey Right : ")) == -1)
    return (-1);
 if ((display_debug(tetris->right)) == -1)
    return (-1);
  if ((my_putstr("\nKey Turn : ")) == -1)
    return (-1);
 if ((display_debug(tetris->key_turn)) == -1)
    return (-1);
  if ((my_putstr("\nKey Drop : ")) == -1)
    return (-1);
 if ((display_debug(tetris->key_drop)) == -1)
    return (-1);
  if ((my_putstr("\nKey Quit : ")) == -1)
    return (-1);
  return (debug_mode_1(tetris));
}
