/*
** create_map.c for  in /home/beche_f/PSU_2015_tetris/src/map
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  1 17:59:33 2016 beche_f
** Last update Thu Mar 17 14:49:21 2016 beche_f
*/

#include "my.h"
void	display_game_map(char **map)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      my_putstr(map[i]);
      my_putchar('\n');
      i++;
    }
}

int	create_map(t_tetris *t)
{
  if ((t->game.game = malloc_maps(t->game.game, t->map_size.height,
				  t->map_size.width)) == NULL)
    return (-1);
  t->game.game = fill_border(t->game.game,
			     t->map_size.width, t->map_size.height);
  t->game.game = fill_top(t->game.game, t->map_size.width, t->map_size.height);

  if ((t->game.next = malloc_maps(t->game.next, 10,
				  8)) == NULL)
    return (-1);
   t->game.next = fill_border(t->game.next,8 ,10 );
   t->game.next = fill_top(t->game.next,8 ,10 );

  if ((t->game.score = malloc_maps(t->game.score, 12,
				  20)) == NULL)
    return (-1);
  t->game.score = fill_border(t->game.score,20 ,12 );
  t->game.score = fill_top(t->game.score,20 ,12 );
  return (0);
}
