/*
** init_ncurses.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Tue Mar 15 12:18:59 2016 beche_f
** Last update Sat Mar 19 18:12:18 2016 beche_f
*/

#include "my.h"

void	init_ncurses()
{
  initscr();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);
}
