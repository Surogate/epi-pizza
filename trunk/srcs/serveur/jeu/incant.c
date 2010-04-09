/*
Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/xfunc.h"

static t_incant	gl_incant[INCANT_NUM + 1] = {
  {1, {1, 0, 0, 0, 0, 0}},
  {2, {1, 1, 1, 0, 0, 0}},
  {2, {2, 0, 1, 0, 2, 0}},
  {4, {1, 1, 2, 0, 1, 0}},
  {4, {1, 2, 1, 3, 0, 0}},
  {6, {1, 2, 3, 0, 1, 0}},
  {6, {2, 2, 2, 2, 2, 1}},
  {0, {0, 0, 0, 0, 0, 0}}
};

void		try_incant(t_packet *packet, t_player *player)
{
  int		i;

  packet->response = NULL;
  if (player->level >= 8)
    if (gl_incant[player->level - 1].nb_player > my_l_size((t_list*)player))
      packet->response = KO;
  i = 0;
  while (i != RESS_NUM) 
    {
      if (gl_incant[player->level - 1].ress_need[i] != player->ress[i])
	packet->response = KO;
      i++;
    }
  if (packet->response == NULL)
    {
      packet->response = OK;
      packet->time = 300;
    }
}
