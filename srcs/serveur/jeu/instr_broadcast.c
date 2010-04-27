/*
** instr_broadcast.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 14:51:20 2010 Florian Chanioux
** Last update Mon Apr 26 10:53:46 2010 pierre1 boutbel
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_list.h"
#include "xfunc.h"
#include "serveur/define.h"
#include "serveur/t_struct.h"
#include "serveur/t_packet.h"
#include "serveur/server.h"
#include "serveur/communication.h"
#include "serveur/communication.h"

void		test_pathfinding_map(t_game *game);

static int	dir_of_msg(t_player *player, t_map *cas)
{
  int		pos;
  int		ref;
  int		i;
  int		j;

  pos = player->dir;
  i = -1;
  j = 0;
  ref = cas->cout;
  while (++i < 8)
    if (ref > cas->card[i]->cout)
    {
      ref = cas->card[i]->cout;
      j = i;
    }
  printf("%i %i \n", pos, j);
  return (pos - j + 1);
}


static void	msg_broad(t_player *player, char **msg, t_rep *rep, char *crep)
{
  int		size;
  int		dir;

  size = 15 + xstrlen(msg[0]) + xstrlen(msg[1]);
  rep->id_player = player->player_id;
  dir = dir_of_msg(player, player->pos);
  rep->mess = xmalloc(sizeof(char) * size);
  snprintf(rep->mess, size, "%s %i,%s\n", msg[0], dir, msg[1]);
  crep = grp_broad(player, rep->mess);
}

void		broadcast(t_packet *packet, t_player *player, t_game *game)
{
  t_player	*pl;
  t_list	*temp;
  int		i;

  pathfinding(player->pos);
  test_pathfinding_map(game);
  temp = game->player;
  i = my_l_size(temp);
  packet->ac_rep = i;
  packet->response = xmalloc(sizeof(*(packet->response)) * (i + 1));
  while (--i >= 0)
    {
      pl = (t_player *)temp->data;
      if (pl->player_id != player->player_id)
	msg_broad(pl, packet->av, packet->response + i, packet->graph_rep);
      else
        {
          packet->response[i].id_player = pl->player_id;
          packet->response[i].mess = xmalloc(5 * sizeof(char));
          snprintf(packet->response[i].mess, 5, "ok\n");
        }
      temp = temp->next;
    }
  reset_pathfinding(game);
}
