/*
** incant.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:30 2010 pierre1 boutbel
** Last update Mon Apr 19 13:49:31 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_game_stc.h"
#include	"t_packet.h"
#include	"xfunc.h"

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
  if (player->level <= 8)
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
      msg[POS_ELEV_K] = cur_pl->level + '0';
      snprintf(packet->response[packet->ac_rep].mess, LEN_ELEV, "%s\n", msg);
      list = list->next;
      packet->ac_rep++;
    }
}

void		try_incant(t_packet *packet, t_player *player)
{
  int		res;

  res = check_incant(player);
  if (res == EXIT_SUCCESS)
    {
      packet->response = xmalloc((my_l_size(player->pos->cas.player) + 2) *
				 sizeof(packet->response));
      packet->response[0].mess = strdup(ELEV_OK);
      packet->response[0].id_player = player->player_id;
      packet->ac_rep = 1;
      create_rep(packet, player);
    }
  else
    packet->response->mess = KO;
}
