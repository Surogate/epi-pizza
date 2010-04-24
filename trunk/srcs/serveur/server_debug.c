/*
** server_debug for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 09:15:22 2010 francois1 ancel
** Last update Sat Apr 24 05:49:11 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "serveur/t_packet.h"

void		debug_packet(t_packet *pak)
{
  int i;

  fprintf (stderr, "========\n");
  if (pak)
    {
      fprintf(stderr, "player id : %i\nplayer : %p\ntype : %i\nac : %i\n", pak->player_id, pak->player, pak->type, pak->ac);
      for(i = 0; i < pak->ac; i++)
	fprintf(stderr, "pak->av[%i] = %s\n", i, pak->av[i]);
      fprintf(stderr, "duration : %i\nend.sec %i\nend.usec %i\nac_rep %i\n", pak->duration, (int)pak->end.tv_sec, (int)pak->end.tv_usec, pak->ac_rep);
      for(i = 0; i < pak->ac_rep; i++)
	fprintf(stderr, "rep %i\nto : %i\nstr : %s\n", i, pak->response[i].id_player, pak->response[i].mess);
      if (pak->graph_rep)
	fprintf(stderr, "graph_rep : %s\n", pak->graph_rep);
    }
  else
    fprintf(stderr, "pak non alloue\n");
  fprintf(stderr, "========\n");
}

void		debug_client(t_client *cli)
{
  int		i;

  fprintf (stderr, "========\n");
  if (cli)
    {
      fprintf(stderr, "sock : %i\nteam : %i\nauth %i\nused : %i\ncons : %i\n", 
	      cli->sock, cli->team, cli->auth, cli->used, cli->cons);
      for(i = 0; i < cli->used; i++)
	debug_packet(cli->packet + ((cli->cons + i) % 10));
    }
  else
    fprintf(stderr, "client non alloue\n");
  fprintf(stderr, "========\n");
}
