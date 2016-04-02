/*
** is_tetrimino_file.c for  in /home/beche_f/PSU_2015_tetris/fran/tetriminos/check
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Mon Feb 29 15:29:23 2016 beche_f
** Last update Mon Feb 29 15:41:29 2016 beche_f
*/

#include "my.h"

int	is_tetrimino_file(char *file)
{
  int	i;
  int	j;
  char	tmp[11];

  tmp[0] = '.';
  tmp[1] = 't';
  tmp[2] = 'e';
  tmp[3] = 't';
  tmp[4] = 'r';
  tmp[5] = 'i';
  tmp[6] = 'm';
  tmp[7] = 'i';
  tmp[8] = 'n';
  tmp[9] = 'o';
  tmp[10] = 0;
  i = 0;
  j = 9;
  while (file[i] != 0)
    i++;
  i--;
  while (j >= 0)
    if (file[i--] != tmp[j--])
      return (-1);
  return (0);
}
