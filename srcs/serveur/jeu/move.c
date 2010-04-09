/*
  Header
*/

#include	<sys/types.h>
#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/xfunc.h"

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
  packet->response = OK;
  packet->time = 7;
}

void		try_turn_right(t_packet *packet, t_player *player)
{
  player->dir = gl_dir[player->dir].dir_right;
  packet->response = OK;
  packet->time = 7;
}

void		try_move(t_packet *packet, t_player *player)
{
  player->pos = player->pos->card[gl_dir[player->dir].front];
  packet->response = OK;
  packet->time = 7;
}
