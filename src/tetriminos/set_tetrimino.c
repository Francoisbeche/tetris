/*
** set_tetrimino.c for  in /home/beche_f/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar  9 21:45:46 2016 beche_f
** Last update Sat Mar 19 17:12:15 2016 beche_f
*/

#include "my.h"

int	malloc_tetrimino(t_elem *elem)
{
  int	y;

  y = 0;
  if ((elem->map = malloc(sizeof(char*) * (elem->height + 1))) == NULL)
    return (-1);
  elem->map[elem->height] = NULL;
  while (y < elem->height)
    {
      if ((elem->map[y] = malloc(sizeof(char) * (elem->width + 1))) == NULL)
	return (-1);
      my_memset(elem->map[y], '\0', elem->width);
      y++;
    }
  return (0);
}

int	check_carac(char **map)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (map[y] != NULL)
    {
      while (map[y][x] != 0)
	{
	  if (map[y][x] != '*' && map[y][x] != ' ')
	    return (-1);
	  x++;
	}
      x = 0;
      y++;
    }
  return (0);
}

int	check_is_good_carac_h(t_elem *elem)
{
  int	y;
  int	x;
  int	nb;
  int	ok;

  ok = 0;
  nb = 0;
  y = 0;
  x = 0;
  while (elem->map[y] != NULL)
    {
      while (elem->map[y][x] != 0)
	{
	  if (elem->map[y][x++] == '*')
	    ok++;
	}
      if (ok > 0)
	nb++;
      ok = 0;
      x = 0;
      y++;
    }
  if (nb < elem->height)
    return (-1);
  return (0);
}

int	check_is_good_carac_w(t_elem *elem)
{
  int	y;
  int	x;
  int	nb;
  int	ok;

  ok = 0;
  nb = 0;
  y = 0;
  x = 0;
  while (elem->map[y] != NULL)
    {
      while (elem->map[y][x] != 0)
	{
	  if (elem->map[y][x++] == '*')
	    nb++;
	}
      if (nb == elem->width)
	ok = 1;
      nb = 0;
      x = 0;
      y++;
    }
  if (ok == 0)
    return (-1);
  return (0);
}

int	recup_tetrimino(t_elem *elem, int y, int i, int fd)
{
  char	*s;

  if ((fd = open(elem->path, O_RDONLY)) == -1)
    return (-1);
  s = get_next_line(fd);
  free(s);
  while ((s = get_next_line(fd)))
    {
      if (my_strlen(s) > elem->width)
	return (-1);
      if (y >= elem->height)
	return (-1);
      if ((elem->map[y] = my_strcat(s, elem->map[y])) == NULL)
	return (-1);
      while (i < elem->width)
	if (elem->map[y][i++] != '*')
	  elem->map[y][i - 1] = ' ';
      i = 0;
      y++;
      free(s);
    }
  return (0);
}
