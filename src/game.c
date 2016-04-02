/*
** game.c for  in /home/beche_f/PSU_2015_tetris/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Fri Mar  4 11:21:03 2016 beche_f
** Last update Sat Mar 19 19:18:17 2016 beche_f
*/
#include <ncurses.h>
#include "my.h"

void	display_map_ncurses(char **map, int cols, int lines)
{
  int	y;
  int	x;

  x = 0;
  y = 0;
  while (map[y] != NULL)
    {
      while (map[y][x] != 0)
	{
	  move(lines, (cols + x));
	  if (map[y][x] > '0' && map[y][x] < '6')
	    {
	      attron(COLOR_PAIR(map[y][x] - 48));
	      addch('*');
	      attroff(COLOR_PAIR(map[y][x] - 48));
	    }
	  else
	    addch(map[y][x]);
	  x++;
	}
      x = 0;
      lines++;
      y++;
    }
}

int		display_game(t_tetris *t)
{
  t->game.next = print_in_next(t);
  if (t->without_next == 1)
    display_map_ncurses(t->game.next, 65, 2);
  display_map_ncurses(t->game.game, 40, 2);
  display_map_ncurses(t->game.score, 2, 2);
  mvprintw(6, 5, "Score %d", t->recap.score);
  mvprintw(8, 5, "Level %d", get_level(t->recap.score));
  mvprintw(9, 5, "Lines: %d", t->recap.nb_line);
  mvprintw(11, 5, "Hight Score: %d", t->recap.high_score);
  mvprintw(3, 5, "Timer: %s ", t->timer);
  t->game.next = clean_next(t);
  return (0);
}

int		algo(t_tetris *t, int c)
{
  char		buff[11];
  int		len;

  my_memset(buff, '\0', 10);
  if ((len =  read(0, buff, 10)) == -1)
    return (-1);
 if (compar_str(buff, t->key_quit) == 0)
   c = 2;
 else if (compar_str(buff, t->key_pause) == 0)
   if (t->is_pause == 0)
     t->is_pause = 1;
   else
     t->is_pause = 0;
 else if (compar_str(buff, t->right) == 0 &&
	  t->pos < (t->map_size.width - 1 - t->atm->width))
   t->pos++;
 else if (compar_str(buff, t->left) == 0 && t->pos > 1)
   if (colision_left(t) == 0)
     t->pos--;
 if ((t->game.game = loop_game(t, t->game.game)) == NULL)
   c = 1;
 else
     display_game(t);
 return (c);
}

void		display_swag()
{
  attron(COLOR_PAIR(2));
  mvprintw(15, 1, " ____  ____ ");
  mvprintw(16, 1, "(_  _)( ___)");
  mvprintw(17, 1, "  )(   )__) ");
  mvprintw(18, 1, " (__) (____)");
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(3));
  mvprintw(15, 13, " ____  ____ ");
  mvprintw(16, 13, "(_  _)(  _ \\");
  mvprintw(17, 13, "  )(   )   / ");
  mvprintw(18, 13, " (__) (_)\\_)");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(1));
  mvprintw(15, 25, " ____  ___ ");
  mvprintw(16, 25, "(_  _)/ __)");
  mvprintw(17, 25, " _)(_ \\__ \\ ");
  mvprintw(18, 25, "(____)(___/");
  attroff(COLOR_PAIR(1));
}

int		game(t_tetris *t)
{
  int		c;

  c = 0;
  init_ncurses();
  while (c == 0)
    {
      display_swag();
      mode(0);
      if (LINES < (t->map_size.height + 3) || COLS < (38 + t->map_size.width))
	{
	  attron(COLOR_PAIR(4));
	  mvprintw(1, 1, "Win too small");
	  attroff(COLOR_PAIR(4));
	}
      else
	c = algo(t, c);
      if (t->is_pause == 0)
	t = timerr(t);
      refresh();
      usleep(t->speed);
      clear();
      mode(1);
    }
  endwin();
return (c);
}
