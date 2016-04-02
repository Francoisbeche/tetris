/*
** malloc_maps.c for  in /home/beche_f/PSU_2015_tetris/src/map
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar  1 17:56:38 2016 beche_f
** Last update Fri Mar  4 16:56:18 2016 beche_f
*/

#include "my.h"
void	free_t_game(t_game *game)
{
  int	i;

  i = 0;
  while (game->game[i] != NULL)
    free(game->game[i++]);
  free(game->game);
  i = 0;
  while (game->next[i] != NULL)
    free(game->next[i++]);
  free(game->next);
  i = 0;
  while (game->score[i] != NULL)
    free(game->score[i++]);
  free(game->score);
}

char	**malloc_maps(char **map, int size_y, int size_x)
{
  int	y;

  y = 0;
  if ((map = malloc(sizeof(char*) * (size_y + 1))) == NULL)
    return (NULL);
  map[size_y] = NULL;
  while (y < size_y)
    {
      if ((map[y] = malloc(sizeof(char) * (size_x + 1))) == NULL)
	return (NULL);
      my_memset(map[y], ' ', size_x);
      y++;
    }
  return (map);
}

char	**fill_top(char **map, int x, int y)
{
  (void)x;
  (void)y;
  my_memset(map[0], '-', x);
  my_memset(map[y-1], '-', x);
  map[0][0] = '/';
  map[0][x - 1] = '\\';
  map[y-1][0] = '\\';
  map[y-1][x - 1] = '/';
  return (map);
}

char	**fill_border(char **map, int	x, int y)
{
  int	i;

  i = 1;
  while (i < y)
    {
      map[i][0] = '|';
      map[i][x - 1] = '|';
      i++;
    }
  return (map);
}
