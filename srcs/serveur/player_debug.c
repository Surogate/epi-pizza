/*
** player_debug for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Apr 21 19:44:08 2010 francois1 ancel
** Last update Mon Apr 26 10:59:26 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "serveur/define.h"
#include "my_list.h"
#include "serveur/t_struct.h"

void	debug_player(t_player *pla)
{
  if (pla)
    printf("===========\nplayer_id : %i\nteam : %i\nlevel : %i\ndir : %i\n===========\n", pla->player_id, pla->team, pla->level, pla->dir);
}

int	list_debug(t_list *list, void (*printf_fct)())
{
  int		i;
  t_list	*tmp;

  printf("\n~~~~~\naddr de la list %p\n", (void *)list);
  i = 0;
  if (list)
    {
      tmp = list;
      while (tmp)
	{
	  printf("num : %i\ntmp->next : %p\n", i, (void *)tmp);
	  if (printf_fct)
	    printf_fct(tmp->data);
	  else
	    printf("data NULL\n");
	  tmp = tmp->next;
	  ++i;
	}
    }
  printf("fin du debug\n~~~~~\n");
  return (EXIT_SUCCESS);
}
