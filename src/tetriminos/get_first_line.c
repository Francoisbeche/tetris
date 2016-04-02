/*
** get_first_line.c for  in /home/beche_f/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar  9 20:39:59 2016 beche_f
** Last update Mon Mar 14 21:06:51 2016 bourre_a
*/

#include "my.h"

t_elem	*get_size(t_elem *elem, char *str, int a)
{
  int   i;
  int   k;
  char  tmp[20];

  my_memset(tmp, '\0', 19);
  i = 0;
  k = 0;
  while (str[i] != ' ')
    {
      tmp[i] = str[i];
      i++;
    }
  i++;
  while (str[i] != 0)
    str[k++] = str[i++];
  str[k] = 0;
  if (a == 0)
    elem->width = my_getnbr(tmp);
  else if (a == 1)
    elem->height = my_getnbr(tmp);
  return (elem);
}

t_elem	*get_color(t_elem *elem, char *str)
{
  int   i;
  char  tmp[20];

  my_memset(tmp, '\0', 19);
  i = 0;
  while (str[i] != 0)
    {
      tmp[i] = str[i];
      i++;
    }
  elem->color = my_getnbr(tmp);
  return (elem);
}

char	*clean_str(char *str)
{
  int	lengh;

  lengh = my_strlen(str) - 1;
  while (str[lengh] == ' ')
    str[lengh--] = 0;
  return (str);
}
int	get_nb_carac(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i++] == ' ')
	nb++;
    }
  nb++;
  return (nb);
}
int	get_first_line(t_elem *elem)
{
  char	*s;
  int	fd;

  if ((fd = open(elem->path, O_RDONLY)) == -1)
    return (-1);
  s = get_next_line(fd);
  clean_str(s);
  if (get_nb_carac(s) != 3)
    return (-1);
  get_size(elem, s, 0);
  get_size(elem, s, 1);
  get_color(elem, s);
  close(fd);
  return (0);
}
