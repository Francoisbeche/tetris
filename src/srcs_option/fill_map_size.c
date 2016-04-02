/*
** fill_map_size.c for fill_map_size in /home/bourre_a/Semestre_2/Systeme_Unix/PSU_2015_tetris/srcs_quentin/srcs
**
** Made by bourre_a
** Login   <bourre_a@epitech.net>
**
** Started on  Tue Feb 23 16:56:01 2016 bourre_a
** Last update Sun Mar 20 14:51:35 2016 bourre_a
*/

#include "my.h"

int	my_strlen_map(char *str)
{
  int	i;

  i = 0;
  while ((str[i] != ',') && (str[i] != '\0'))
    i++;
  return (i);
}

char	*fill_number_1(char *size, int i, char *number_1)
{
  while (size[i] != ',')
    {
      if ((size[i] < '0') || (size[i] > '9'))
	return (NULL);
      number_1[i] = size[i];
      i++;
    }
  number_1[i] = 0;
  return (number_1);
}

char	*fill_number_2(char *size, int i, int j, char *number_2)
{
 while (size[i] != '\0')
    {
      if ((size[i] < '0') || (size[i] > '9'))
	return (NULL);
      number_2[j++] = size[i++];
    }
 number_2[j] = 0;
 return (number_2);
}

int	get_my_tetris(char *number_1, char *number_2, t_tetris *tetris)
{
  int	num1;
  int	num2;

  num1 = my_getnbr(number_1);
  num2 = my_getnbr(number_2);
  if ((num1 <= 0) || (num2 <= 0))
    return (-1);
  tetris->map_size.height = num1;
  tetris->map_size.width = num2;
  return (0);
}

int	fill_map_size(char *size, t_tetris *tetris)
{
  char	*number_1;
  char	*number_2;
  int	size_number_1;
  int	size_number_2;
  int	i;

  i = 0;
  if ((size = get_my_size(size)) == NULL)
    return (-1);
  size_number_1 = my_strlen_map(size);
  size_number_2 = (my_strlen(size) - (my_strlen_map(size) + 1));
  if ((number_1 = malloc(sizeof(char) * size_number_1)) == NULL)
    return (-1);
  if ((number_2 = malloc(sizeof(char) * size_number_2)) == NULL)
    return (-1);
  if ((number_1 = fill_number_1(size, i, number_1)) == NULL)
    return (-1);
  i = size_number_1 + 1;
  if ((number_2 = fill_number_2(size, i, 0, number_2)) == NULL)
    return (-1);
  if ((get_my_tetris(number_1, number_2, tetris)) == -1)
    return (-1);
  return (0);
}
