/*
** arrow.c for  in /home/beche_f/testtetris/PSU_2015_tetris/src
**
** Made by beche_f
** Login   <beche_f@epitech.net>
**
** Started on  Wed Mar 16 14:33:00 2016 beche_f
** Last update Wed Mar 16 20:08:44 2016 beche_f
*/

char	*modif_my_key_str(char   *str) /* t_tetris *t */
{
  if ((str[0] == '^') && (str[1] == 'E') && (str[2] == 'O'))
    {
      str[0] = 27;
      str[1] = 91;
      str[2] = str[3];
      str[3] = '\0';
    }
  return (str);
}
