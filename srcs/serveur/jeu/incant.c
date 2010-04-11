/*
Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdlib.h>
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

static int	check_incant(t_player *player)
{
  if (player->level >= 8)
    if (gl_incant[player->level - 1].nb_player > my_l_size((t_list*)player))
      return (EXIT_FAILURE);
  i = 0;
  while (i != RESS_NUM)
    {
      if (gl_incant[player->level - 1].ress_need[i] != player->ress[i])
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}

void		try_incant(t_packet *packet, t_player *player)
{
  t_list	*cur_player;
  char		msg[LEN_ELEV];
  int		res;
  int		i;

  res = check_incant(player);
  if (res == EXIT_SUCCESS)
    {
      cur_player = xmalloc((my_l_size(player->pos->cas.player) + 2) *
			   sizeof(packet->response));
      i = 1;
      packet->response[0].mess = ELEV_OK;
      packet->response[0].id_player = player->player_id;
      while (cur_player != NULL)
	{
	  cur_player->level++;
	  packet->response[i].id_player = cur_player->player_id;
	  msg[POS_ELEV_K] = cur_player->level;
	  packet->response[i++].mess = msg;
	  cur_player = cur_player->next;
	}
    }
  else
    packet->response->mess = KO;
}
