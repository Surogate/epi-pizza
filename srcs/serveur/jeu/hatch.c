/*
** hatch.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Apr 12 19:29:06 2010 Florian Chanioux
** Last update Mon Apr 12 19:32:47 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<stdlib.h>
#include	"my_list.h"
#include	"define.h"
#include	"t_packet.h"
#include	"t_struct.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

void		do_fork(t_game *game, t_player *player)
{
/*  t_eggs	*cur_egg;
  t_eggs	*new_egg;

  new_egg = xmalloc(sizeof(t_eggs *));
  cur_egg = game->eggs;
  while (cur_egg != NULL)
    cur_egg = cur_egg->next;
  (t_list *)new_egg->next = NULL;
  new_egg->team = player->team;
  new_egg->cas = player->cas;
  (t_list*)cur_egg->next = new_egg;*/
}

void		try_fork(t_packet *packet, t_player *player)
{
  packet->response->mess = OK;
  packet->response->id_player = player->player_id;
}
