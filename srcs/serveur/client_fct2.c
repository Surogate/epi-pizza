/*
** client_fct.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 11:35:02 2010 francois1 ancel
** Last update Tue Apr 27 17:47:46 2010 pierre1 boutbel
*/

#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "serveur/define.h"
#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "serveur/t_packet.h"
#include "serveur/t_svr_stc.h"
#include "serveur/t_struct.h"
#include "serveur/server_kick.h"
#include "serveur/instruction.h"
#include "serveur/server_debug.h"

int		fill_pak(t_packet *pak, char *str, t_client *cli)
{
  pak->type = 0;
  pak->ac_rep = -1;
  pak->response = NULL;
  pak->end.tv_sec = 0;
  pak->end.tv_usec = 0;
  pak->graph_rep = NULL;
  return (EXIT_SUCCESS);
}
