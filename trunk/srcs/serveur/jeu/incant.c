/*
** incant.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:30 2010 pierre1 boutbel
** Last update Sat Apr 24 05:49:08 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_game_stc.h"
#include	"serveur/t_packet.h"
#include	"xfunc.h"
#include	"serveur/server_ending.h"

static t_incant	gl_incant[INCANT_NUM + 1] = {
  {1, {0, 1, 0, 0, 0, 0, 0}},
  {2, {0, 1, 1, 1, 0, 0, 0}},
  {2, {0, 2, 0, 1, 0, 2, 0}},
  {4, {0, 1, 1, 2, 0, 1, 0}},
  {4, {0, 1, 2, 1, 3, 0, 0}},
  {6, {0, 1, 2, 3, 0, 1, 0}},
  {6, {0, 2, 2, 2, 2, 2, 1}},
  {0, {0, 0, 0, 0, 0, 0, 0}}
};

static int	check_incant(t_player *player)
{
  int		i;
  int		len;
  
  len = my_l_size(player->pos->cas.player);
  if (player->level < 8)
    if (gl_incant[player->level - 1].nb_player != len)
      return (EXIT_FAILURE);
  i = 1;
  while (i != RESS_NUM)
    {
      if (gl_incant[player->level - 1].ress_need[i] != 
	  player->pos->cas.ress[i])
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}

void		create_rep(t_packet *packet, t_player *player)
{
  t_list	*list;
  t_player	*cur_pl;
  char		*msg;

  msg = strdup(ELEV_DONE);
  list = player->pos->cas.player;
  while (list->data != NULL)
    {
      cur_pl = (t_player *)list->data;
      cur_pl->level = cur_pl->level + 1;
      packet->response[packet->ac_rep].id_player = cur_pl->player_id;
      packet->response[packet->ac_rep].mess = xmalloc(LEN_ELEV * 
						      sizeof(char));
      msg[POS_ELEV_K] = cur_pl->level + '0';
      snprintf(packet->response[packet->ac_rep].mess, LEN_ELEV + 2, "%s\n", 
	       msg);
      packet->ac_rep++;
      list = list->next;
    }
}

void		try_incant(t_packet *packet, t_player *player, t_game *game)
{
  int		res;

  res = check_incant(player);
  if (res == EXIT_SUCCESS)
    {
      packet->response = xmalloc((my_l_size(player->pos->cas.player) + 1) *
				 sizeof(*(packet->response)));
      packet->response[0].mess = xmalloc((xstrlen(ELEV_OK) + 2) * sizeof(char));
      snprintf(packet->response[0].mess, xstrlen(ELEV_OK) + 2, "%s\n", ELEV_OK);
      packet->response[0].id_player = player->player_id;
      packet->ac_rep = 1;
      create_rep(packet, player);
      packet->graph_rep = grp_incant_done(player);
      is_ending(game);
    }
  else
    {
      packet->response = xmalloc(sizeof(t_rep));
      packet->response->mess = xmalloc(LEN_OK * sizeof(char));
      snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
      packet->response->id_player = packet->player_id;
      packet->ac_rep = 1;
    }
}
