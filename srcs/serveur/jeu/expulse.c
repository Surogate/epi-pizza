/*
** expulse.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Tue Apr 13 09:15:30 2010 pierre1 boutbel
** Last update Sat Apr 24 05:49:08 2010 Florian Chanioux
*/


#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_packet.h"
#include	"serveur/t_game_stc.h"
#include	"xfunc.h"

static void	expulse_list_msg(t_packet *packet, t_player *player)
{
  char		*msg;
  t_player	*pl;
  t_list	*cur_player;

  msg = strdup(EXPULSE_VIC);
  cur_player = (t_list *)player->pos->cas.player;
  while (cur_player->data != NULL)
    {
      pl = (t_player*)cur_player->data;
      if (pl->player_id != player->player_id)
	{
	  packet->response[packet->ac_rep].mess = xmalloc(LEN_EXP * 
							  sizeof(char));
	  msg[POS_EXP_K] = (player->dir + 1) % 4 + '0';
	  snprintf(packet->response[packet->ac_rep].mess, LEN_EXP + 1, 
		   "%s\n", msg);
	  pl->pos = pl->pos->card[(player->dir + 1) % 4];
	  packet->response[packet->ac_rep].id_player = pl->player_id;
	  packet->ac_rep++;
	}
      cur_player = cur_player->next;
    }
}

void		do_expulse(t_packet *packet, t_player *player)
{
  packet->response = xmalloc((my_l_size(player->pos->cas.player) + 1) *
			     sizeof(*(packet->response)));
  packet->response[0].mess = xmalloc((LEN_OK + 2) * sizeof(char));
  snprintf(packet->response[0].mess, LEN_OK, "%s\n", OK);
  packet->response[0].id_player = player->player_id;
  packet->ac_rep = 1;
  expulse_list_msg(packet, player);
}

void		try_expulse(t_packet *packet, t_player *player)
{
  if (my_l_size(player->pos->cas.player) == 1)
    {
      packet->response = xmalloc(sizeof(t_rep));
      packet->response->mess = xmalloc(LEN_OK * sizeof(char));
      snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
      packet->response->id_player = packet->player_id;
      packet->ac_rep = 1;
    }
  else
    {
      packet->graph_rep = grp_expulse(player);
      do_expulse(packet, player);
    }
}
