/*
** mode_canonique.c for mode_canonique in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Fri Mar 11 16:31:09 2016 bourre_a
** Last update Sat Mar 19 17:38:59 2016 beche_f
*/

/* #include <ncurses/curses.h> */

#include "my.h"

int	mode_0(struct termios new ,struct termios old)
{
  ioctl(0, TCGETS, &new);
  ioctl(0, TCGETS, &old);
  new.c_lflag &= ~ECHO;
  new.c_lflag &= ~ICANON;
  new.c_cc[VMIN] = 0;
  new.c_cc[VTIME] = 1;
  ioctl(0, TCSETS, &new);
  return (0);
}

int	mode(int i)
{
  static struct termios new;
  static struct termios old;

  if ((i == 0) || (i == 1) || ( i == 2))
    {
      if (i == 0)
	{
	  mode_0(new, old);
	}
      else if (i == 2)
	{
	  ioctl(0, TCGETS, &new);
	  ioctl(0, TCGETS, &old);
	  new.c_lflag &= ~ECHO;
	  new.c_lflag &= ~ICANON;
	  ioctl(0, TCSETS, &new);
	}
      else if (i == 1)
	ioctl(0, TCSETS, &old);
    }
  else
    return (-1);
  return (0);
}
