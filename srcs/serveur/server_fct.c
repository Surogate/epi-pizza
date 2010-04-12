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
#include "client_fct.h"

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

static void	instr_catch(char *str, t_client *cli, t_game *game)
{
  int		i;

  if (client_parse_instr(str, cli) == EXIT_SUCCESS)
    {
      /*
	 if team indefinis alors check si on peut cree le joueurs
	 sinon definir le temps associer a cette instr
	 if (!cli->team)
	 result = authent(cli->packet + cli->cons);
	 else
	 result = det_duration(cli->packet + cli->cons);
      */
      i = 0;
      while (i < cli->packet[cli->cons].ac)
	{
	  printf("readed : %s\n", cli->packet[cli->cons].av[i]);
	  i++;
	}
      /* if (result == EXIT_FAILURE) */
      free_packet(cli); /* si l'instr est invalide */
    }
  game = game;
}

static void	free_client(t_client *cli)
{
  close(cli->sock);
  while (cli->used)
    free_packet(cli);
  free (cli);
}

int		close_client(t_vector *client, t_select *slt_par)
{
  t_client	*tmp;

  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    FD_CLR(tmp->sock, &(slt_par->fd_read));
  client->destruc(client, free_client);
  return (EXIT_SUCCESS);
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
	      client->erase(client, client->gns_pos, free_client);
	    }
	  else if ((readed = cbuf_read(&(tmp->cbuf), check_read)))
	    instr_catch(readed, tmp, game);
	}
    }
  return (EXIT_SUCCESS);
}
