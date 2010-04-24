/*
** split.c for minishell in /u/all/pierro_a/cu/rendu/c/minishell1
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Nov 15 20:03:40 2009 frederic1 pierronnet
** Last update Tue Dec 22 16:34:28 2009 frederic1 pierronnet
*/
#include <string.h>

int	find_size(char *name, char sep)
{
  int	cont;
  int	size;
  int	flag;

  cont = 0;
  flag = 1;
  size = 1;
  while (name[cont] != 0)
    {
      if (name[cont] == sep)
	{
	  if (flag == 0)
	    size++;
	}
      else
        flag = 0;
      cont++;
    }
  return (size);
}

void	*xmalloc(int size);

char	**split(char *name, char sep)
{
  char	**argv;
  int	cont;
  int	size;
  int	cont_argv;

  argv = xmalloc((find_size(name, sep) + 1) * sizeof(*argv));
  cont_argv = 0;
  cont = 0;
  while (name[cont] != 0)
    {
      size = 0;
      if (name[cont] != sep)
        {
          while (name[cont + size] != sep &&
		 name[cont + size] != 0)
	    size++;
          argv[cont_argv] = xmalloc((size + 1) * sizeof(**argv));
          strncpy(argv[cont_argv], &name[cont], size);
	  argv[cont_argv][size] = 0;
          cont = cont + size - 1;
          cont_argv++;
        }
      cont++;
    }
  argv[cont_argv] = 0;
  return (argv);
}
