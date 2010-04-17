/*
** move.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:56 2010 pierre1 boutbel
** Last update Wed Apr 14 13:20:15 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

static t_dir_m	gl_dir[5] = {
  {DIR_N, DIR_O, M_N, DIR_E},
  {DIR_E, DIR_N, M_E, DIR_S},
  {DIR_S, DIR_E, M_S, DIR_O},
  {DIR_O, DIR_S, M_O, DIR_N},
  {0, 0, 0, 0}
};

void		try_turn_left(t_packet *packet, t_player *player)
{
  player->dir = gl_dir[player->dir].dir_left;
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(3 * sizeof(char));
  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
}

void		try_turn_right(t_packet *packet, t_player *player)
{
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(3 * sizeof(char));
  player->dir = gl_dir[player->dir].dir_right;
  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
}

int		find_player_by_id(void *data, void *ref)
{
  t_player	*pl_data;
  t_player	*pl_ref;

  pl_data = (t_player*)data;
  pl_ref = (t_player*)ref;
  if (pl_data->player_id == pl_ref->player_id)
    return (0);
  else
    return (1);
}

void		try_move(t_packet *packet, t_player *player)
{
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(3 * sizeof(char));

  player->pos->cas.player = my_l_rm(player->pos->cas.player, 
				    player->player_id, find_player_by_id);
  player->pos = player->pos->card[gl_dir[player->dir].front];
  


  /*Retirer de la liste des joueurs de la case*/

  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
}
