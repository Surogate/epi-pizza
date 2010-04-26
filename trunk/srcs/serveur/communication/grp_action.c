/*
**  Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	<stdlib.h>

#include	"serveur/define.h"
#include	"my_list.h"
#include	"serveur/t_struct.h"
#include	"serveur/communication.h"
#include	"xfunc.h"


static int	find_player(t_player *ref, t_player *data)
{
  if (data && (ref->player_id == data->player_id))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

char		*grp_do_incant(t_game *game, int id_player)
{
  t_player	*player;
  t_player	ref;

  ref.player_id = id_player;
  player = my_l_find(game->player, &ref, find_player);
  return (pic(NULL, player));
}

char		*grp_incant_done(t_player *player, int res)
{
  t_player	*pl;
  t_list	*list;
  char		*msg;

  msg = pie(NULL, player, res);
  list = player->pos->cas.player;
  while (list->data != NULL)
    {
      pl = (t_player *)list->data;
      msg = plv(msg, pl);
      list = list->next;
    }
  msg = bct(msg, player->pos);
  return (msg);
}

/*APPELER GRP_EXPULSE AVANT D'EXPULSER !!!!!*/
char		*grp_expulse(t_player *player)
{
  t_player	*pl;
  t_list	*list;
  char		*msg;

  msg = pex(NULL, player);
  list = player->pos->cas.player;
  while (list->data != NULL)
    {
      pl = (t_player *)list;
      if (pl->player_id != player->player_id)
	msg = ppo(msg, pl);
      list = list->next;
    }
  return (msg);
}

char		*grp_broad(t_player *player, char *broad)
{
  return (pbc(NULL, player, broad));
}
