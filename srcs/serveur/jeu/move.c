/*
  Header
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
  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
}

void		try_turn_right(t_packet *packet, t_player *player)
{
  player->dir = gl_dir[player->dir].dir_right;
  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
}

void		try_move(t_packet *packet, t_player *player)
{
  player->pos = player->pos->card[gl_dir[player->dir].front];
  
  /*Retirer de la liste des joueurs de la case*/

  packet->response->mess = OK;
  packet->response->id_player = packet->player_id;
}
