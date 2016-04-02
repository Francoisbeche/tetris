/*
** free_stuct_tetris.c for free_struct_tetris in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris/PSU_2015_tetris/src/srcs_option
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Tue Mar  8 14:41:30 2016 bourre_a
** Last update Tue Mar  8 14:55:54 2016 bourre_a
*/

#include "my.h"

void	free_struct_tetris(t_tetris *tetris)
{
  free(tetris->key_left);
  free(tetris->key_right);
  free(tetris->key_turn);
  free(tetris->key_drop);
  free(tetris->key_quit);
  free(tetris->key_pause);
}
