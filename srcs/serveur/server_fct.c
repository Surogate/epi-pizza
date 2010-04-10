/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Sat Apr 10 15:11:57 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>

#include "define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_struct.h"
#include "t_svr_stc.h"

static int	check_read(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '\n')
    i++;
  if (str[i])
    return (i);
  return (0);
}


void		instr_catch(char *str, t_client *cli, t_game *game)
{
  printf("readed : %s\n", str);
  cli = cli;
  game = game;
}

int		execute_order_66(t_vector *client, t_select *slt_par,
				 t_game *game)
{
  t_client	*tmp;
  char		*readed;

  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    {
      if (FD_ISSET(tmp->sock, &(slt_par->fd_read)))
	{
	  if (cbuf_write(&tmp->cbuf, tmp->sock) == EXPIPE)
	    {
	      printf("client %i timeout\n", tmp->sock);
	      FD_CLR(tmp->sock, &(slt_par->fd_read));
	      client->erase(client, client->gns_pos, free);
	    }
	  else if ((readed = cbuf_read(&(tmp->cbuf), check_read)))
	    instr_catch(readed, tmp, game);
	}
    }
  return (EXIT_SUCCESS);
}
