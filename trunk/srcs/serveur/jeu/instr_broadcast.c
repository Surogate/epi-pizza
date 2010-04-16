/*
** instr_broadcast.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 14:51:20 2010 Florian Chanioux
** Last update Fri Apr 16 15:39:24 2010 Florian Chanioux
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

void		dir_of_msg(int player_id, char **msg, t_rep *rep)
{
  int		size;

  size = 3;
  size += strlen(msg[0]);
  size += strlen(msg[1]);
  rep->id_player = player_id;
  rep->mess = xmalloc(sizeof(char) * size);
  memset(rep->mess, 0, sizeof(char) * size);
  sprintf(rep->mess, "%s %i,%s", msg[0], player_id, msg[1]);
}


void		broadcast(t_packet *packet, t_player *player, t_game *game)
{
  t_player	*pl;
  t_list	*temp;
  int		i;

  pathfinding(player->pos);
  temp = game->player;
  i = my_l_size(temp) - 2;
  packet->ac_rep = i - 1;
  packet->response = xmalloc(sizeof(t_rep) * (packet->ac_rep - 1));
  while (i < packet->ac_rep)
  {
    pl = (t_player*)temp->data;
    if (pl->player_id != player->player_id)
      dir_of_msg(pl->player_id, packet->av, &(packet->response[i]));
    temp = temp->next;
  }
  reset_pathfinding(game);
}
