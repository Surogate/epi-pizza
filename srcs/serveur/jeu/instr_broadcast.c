/*
** instr_broadcast.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 14:51:20 2010 Florian Chanioux
** Last update Fri Apr 16 15:13:11 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "t_packet.h"
#include "server.h"

char *dir_of_msg(t_player *player)
{
  return (NULL);
}


void		broadcast(t_packet *packet, t_player *player, t_game *game)
{
  t_player	*pl;
  t_list	*temp;
  int		i;

  pathfinding(game, player->pos);
  temp = game->player;
  i = my_l_size(temp) - 2;
  packet->ac_rep = i - 1;
  packet->response = xmalloc(sizeof(t_rep) * (packet->ac_rep - 1));
  while (i < packet->ac_rep)
  {
    packet->response[i].mess = dir_of_msg(temp->data);
    temp->next;
  }
  packet = packet;
  reset_pathfinding(game);
}
