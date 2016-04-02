/*
** help.c for help in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Tue Feb 23 13:00:23 2016 bourre_a
** Last update Fri Mar 18 14:41:34 2016 bourre_a
*/

#include "my.h"

int	finish_display()
{
  if ((my_putstr("  -kd --key-drop={K}    Set default DROP on key K\n")) == -1)
    return (-1);
  if ((my_putstr("  -kq --key_quit={K}    Quit program when ")) == -1)
    return (-1);
  if ((my_putstr("press key K\n")) == -1)
    return (-1);
  if ((my_putstr("  -kp --key-pause={K}   Pause and restart ")) == -1)
    return (-1);
  if ((my_putstr("game when press key K\n")) == -1)
    return (-1);
  if ((my_putstr("  --map-size={row,col}  Set game size at row, col\n")) == -1)
    return (-1);
  if ((my_putstr("  -w --without-next     Hide next tetrimino\n")) == -1)
    return (-1);
  if ((my_putstr("  -d --debug            Debug mode\n")) == -1)
    return (-1);
  return (0);
}

int	display_help(t_tetris *tetris)
{
  if ((my_putstr("Usage: ")) == -1)
    return (-1);
  if ((my_putstr(tetris->name_binari)) == -1)
    return (-1);
  if ((my_putstr(" [option]\nOption:\n")) == -1)
    return (-1);
  if ((my_putstr("  --help                Display this")) == -1)
    return (-1);
  if ((my_putstr(" help\n")) == -1)
    return (-1);
  if ((my_putstr("  -l --level={num}      Start Tetris at level num\n")) == -1)
    return (-1);
  if ((my_putstr("  -kl --key-left={K}    Move tetrimino on ")) == -1)
    return (-1);
  if ((my_putstr("LEFT with key K\n")) == -1)
    return (-1);
  if ((my_putstr("  -kr --key-right={K}   Move tetrimino ")) == -1)
    return (-1);
  if ((my_putstr("on RIGHT with key K\n")) == -1)
    return (-1);
  if ((my_putstr("  -kt --key-turn={K}    Turn tetrimino with key K\n")) == -1)
    return (-1);
  if ((finish_display()) == -1)
    return (-1);
  return (0);
}
