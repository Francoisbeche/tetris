/*
** main.c for  in /home/beche_f/PSU_2015_tetris/src/tetriminos
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar  9 20:16:18 2016 beche_f
** Last update Wed Mar  9 20:17:57 2016 beche_f
*/
#include "my.h"
int	main()
{
  t_list	*list;

  list = NULL;
  load_tetrimino(list);
  return (0);
}
