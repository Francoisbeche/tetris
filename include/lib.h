/*
** lib.h for  in /home/beche_f/testtetris/PSU_2015_tetris/include
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar 16 14:13:12 2016 beche_f
** Last update Wed Mar 16 14:16:51 2016 beche_f
*/

#ifndef LIB_H_
#define LIB_H_
#include "my.h"

int	my_strlen(char*);
int	my_putchar(char);
int	my_putstr(char*);
int	my_puterror(char*);
int	my_getnbr(char*);
char	*my_strcat(char*, char*);
char	*my_strcpy(char*, char*, int);
int	my_put_nbr(int);
char	*my_memset(char*, char, int);
void	display_char_2d(char**);
#endif /* !LIB_H_ */
