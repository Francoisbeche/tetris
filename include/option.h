/*
** option.h for option in /home/bourre_a/Semestre_2/Systeme_Unix/Tetris/PSU_2015_tetris/include
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Wed Mar  2 11:11:09 2016 bourre_a
** Last update Fri Mar  4 14:42:56 2016 bourre_a
*/

#ifndef OPTION_H_
#define OPTION_H_

typedef struct s_option
{
  char	*option_with_arg;
  char	*option;
  char	*arg;
  char	*next_arg;
  int	i;
  int	debug;
  int	numero;
  int	size;
  int	ac;
}	t_option;

#endif /* !OPTION_H_ */
