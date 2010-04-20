/*
** instr_broadcast.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 14:51:20 2010 Florian Chanioux
** Last update Tue Apr 20 17:19:32 2010 Florian Chanioux
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "t_packet.h"
#include "server.h"
#include "xfunc.h"

static int	dir_of_msg(t_player *player, t_map *cas)
{
  int		or[4];
  int		pos;
  int		res;
  int		i;
  int		j;

  pos = player->dir;
  i = -1;
  j = 0;
  while (++i < 8)
    if (cas->card[i]->cout == (cas->cout - 1))
      or[j++] = i;
  res = rand() % j;
  return (pos - or[res] + 1);
}


static void	msg_broad(t_player *player, char **msg, t_rep *rep)
{
  int		size;
  int		dir;

  size = 14;
  size += strlen(msg[0]);
  size += strlen(msg[1]);
  rep->id_player = player->player_id;
  dir = dir_of_msg(player, player->pos);
  rep->mess = xmalloc(sizeof(char) * size);
  memset(rep->mess, 0, sizeof(char) * size);
  snprintf(rep->mess, size, "%s %i,%s\n", msg[0], dir, msg[1]);
}

void		broadcast(t_packet *packet, t_player *player, t_game *game)
{
  t_player	*pl;
  t_list	*temp;
  int		i;

  pathfinding(player->pos);
  temp = game->player;
  i = my_l_size(temp);
  packet->ac_rep = i - 1;
  packet->response = xmalloc(sizeof(t_rep) * i);
  while (--i > 0)
  {
    pl = (t_player *)temp->data;
    if (pl->player_id != player->player_id)
      msg_broad(pl, packet->av, &(packet->response[i]));
    else
    {
      packet->response[i].id_player = pl->player_id;
      strncpy(packet->response[i].mess, OK, strlen(OK));
    }
    temp = temp->next;
  }
  reset_pathfinding(game);
}
