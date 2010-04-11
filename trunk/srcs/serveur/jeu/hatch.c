/*
**	Header
*/

#include	<sys/types.h>
#include	<stdlib.h>
#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/xfunc.h"

void		do_fork(t_game *game, t_player player)
{
  t_eggs	*cur_egg;
  t_eggs	*new_egg;

  new_egg = xmalloc(sizeof(t_eggs *));
  cur_egg = game->eggs;
  while (cur_egg != NULL)
    cur_egg = cur_egg->next;
  (t_list *)new_egg->next = NULL;
  new_egg->team = player->team;
  new_egg->cas = player->cas;
  (t_list*)cur_egg->next = new_egg;
}

void		try_fork(t_packet *packet, t_player *player)
{
  packet->response->mess = OK;
  packet->response->id_player = player->player->id;
}
