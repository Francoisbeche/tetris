/*
** tri_file.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar 11 15:06:17 2016 beche_f
** Last update Wed Mar 16 14:05:11 2016 beche_f
*/

#include "my.h"

char	**reverse_reset_char_2d(char **map)
{
  int	i;
  char	name[11];

  name[0] ='.' ;
  name[1] = 't';
  name[2] = 'e';
  name[3] = 't';
  name[4] = 'r';
  name[5] = 'i';
  name[6] = 'm';
  name[7] = 'i';
  name[8] = 'n';
  name[9] = 'o';
  name[10] = 0;;
  i = 0;
  while (map[i] != NULL)
    {
      my_strcat(name, map[i]);
      i++;
    }
  return (map);
}

char	**get_only_name(char **map)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (map[y] != NULL)
    {
      while (map[y][x] != '.')
	x++;
      map[y][x] = 0;
      x = 0;
      y++;
    }
  return (map);
}
char	**reset_char_2d(char **map)
{
  int	y;

  y = 0;
  while (map[y] != NULL)
    {
      my_memset(map[y], '\0', 254);
      y++;
    }
  return (map);
}

char	**tri_file(char **map, char **dest)
{
  int	i;
  int	a;
  int	b;

  b = 0;
  a = 0;
  i = 0;
  while (i < 255)
    {
      while (map[a] != NULL)
	{
	  if (map[a][0] == i)
	    {
	      my_strcat(map[a], dest[b]);
	      b++;
	    }
	  a++;
	}
      a = 0;
      i++;
    }
  return (dest);
}
