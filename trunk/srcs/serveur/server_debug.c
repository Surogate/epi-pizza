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

#include "s_vector.h"
#include "s_cbuf.h"
#include "serveur/t_packet.h"
#include "serveur/t_svr_stc.h"

void		debug_packet(t_packet *pak, char *str)
{
  int i;
  FILE *debug;
  
  debug = fopen("packet.log", "a");
  if (!debug)
    return ;
  if (str)
    fprintf (debug, "======== %s\n", str);
  else
    fprintf (debug, "========\n");
  if (pak)
    {
      fprintf(debug, "player id : %i\nplayer : %p\ntype : %i\nac : %i\n", pak->player_id, pak->player, pak->type, pak->ac);
      for(i = 0; i < pak->ac; i++)
	fprintf(debug, "pak->av[%i] = %s\n", i, pak->av[i]);
      fprintf(debug, "duration : %i\nend.sec %i\nend.usec %i\nac_rep %i\n", pak->duration, (int)pak->end.tv_sec, (int)pak->end.tv_usec, pak->ac_rep);
      for(i = 0; i < pak->ac_rep; i++)
	fprintf(debug, "rep %i\nto : %i\nstr : %s\n", i, pak->response[i].id_player, pak->response[i].mess);
      if (pak->graph_rep)
	fprintf(debug, "graph_rep : %s\n", pak->graph_rep);
    }
  else
    fprintf(debug, "pak non alloue\n");
  fprintf(debug, "########\n");
  fclose(debug);
}

void		debug_client(t_client *cli, char *str)
{
  int		i;
  FILE		*debug;

  debug = fopen("client.log", "a");
  if (!debug)
    return ;
  if (str)
    fprintf (debug, "******* %s ******\n", str);
  else
    fprintf (debug, "*******\n");
  if (cli)
    {
      fprintf(debug, "sock : %i\nteam : %i\nauth : %i\nused : %i\ncons : %i\n", 
	      cli->sock, cli->team, cli->auth, cli->used, cli->cons);
      for(i = 0; i < cli->used; i++)
	debug_packet(cli->packet + ((cli->cons + i) % 10), str);
    }
  else
    fprintf(debug, "client non alloue\n");
  fprintf(debug, "$$$$$$$\n");
  fclose(debug);
}

void		debug_instr(t_packet *pak)
{
  int		i;
  FILE		*debug;
  
  debug = fopen("client.log", "a");
  if (!debug)
    return ;
  i = 0;
  fprintf(debug, "pak->ac = %i\n", pak->ac);
  while (i < pak->ac)
    {
      fprintf(debug, "pak->av[%i] = %s\n", i, pak->av[i]);
      ++i;
    }
  fclose(debug);
}
