/*
** expulse.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Tue Apr 13 09:15:30 2010 pierre1 boutbel
** Last update Sun Apr 18 12:53:22 2010 pierre1 boutbel
*/


#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdio.h>
#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

void		do_expulse(t_packet *packet, t_player *player)
{
  char		*msg;
  t_player	*pl;
  t_list	*cur_player;

  packet->response = xmalloc((my_l_size(player->pos->cas.player) + 1) *
			     sizeof(packet->response));
  packet->response[0].mess = xmalloc(4 * sizeof(char));
  packet->response[0].mess = OK;
  cur_player = (t_list *)player->pos->cas.player;
  msg = strdup(EXPULSE_VIC);
  packet->ac_rep = 1;
  while (cur_player->data != NULL)
    {
      pl = (t_player*)cur_player->data;
      packet->response[packet->ac_rep].mess = xmalloc(LEN_EXP * sizeof(char));
      msg[POS_EXP_K] = (player->dir + 1) % 4 + '0';
      packet->response[packet->ac_rep].mess = msg;
      pl->pos = pl->pos->card[(player->dir + 1) % 4];
      packet->response[packet->ac_rep++].id_player = pl->player_id;
      cur_player = cur_player->next;
    }
}

void		try_expulse(t_packet *packet, t_player *player)
{
  if (my_l_size(player->pos->cas.player) == 1)
    {
      packet->response = xmalloc(sizeof(t_rep));
      packet->response->mess = xmalloc(4 * sizeof(char));
      packet->response->mess = KO;
      packet->response->id_player = packet->player_id;
      packet->ac_rep = 1;
    }
  else
    do_expulse(packet, player);
}
