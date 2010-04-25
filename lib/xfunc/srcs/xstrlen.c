/*
** xstrlen for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Apr 25 16:21:39 2010 francois1 ancel
** Last update Sun Apr 25 16:21:39 2010 francois1 ancel
*/

int	xstrlen(char *str)
{
  int	i;

  if (!str)
    return (0);
  i = -1;
  while (str[++i]);
  return (i);
}
