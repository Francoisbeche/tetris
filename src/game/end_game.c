/*
** end_game.c for  in /home/beche_f/PSU_2015_tetris/src/game
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Sat Mar 19 16:58:38 2016 beche_f
** Last update Sat Mar 19 16:59:13 2016 beche_f
*/

#include "my.h"

char	**end_game(char **map)
{
  int   x;

  x = 0;
  while (map[0][x] != 0)
    {
      if (map[0][x] != '-' && map[0][x] != '/' &&
	  map[0][x] != '\\' && map[0][x] != '|')
	return (NULL);
      x++;
    }
  return (map);
}
