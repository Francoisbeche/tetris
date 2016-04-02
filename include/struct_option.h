/*
** struct_option.h for struct_option in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin
** 
** Made by bourre_a
** Login   <bourre_a@epitech.net>
** 
** Started on  Mon Feb 29 16:30:39 2016 bourre_a
** Last update Tue Mar  1 14:08:53 2016 bourre_a
*/

typedef struct s_option
{
  char	*option_with_arg;
  char	*option;
  char	*arg;
  char	*next_arg;
  int	i;
  int	debug;
  int	numero;
}	t_option;
