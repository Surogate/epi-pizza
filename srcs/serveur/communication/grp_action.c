/*
**  Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdarg.h>

#include	"define.h"
#include	"my_list.h"
#include	"t_struct.h"
#include	"communication.h"
#include	"xfunc.h"

char		*grp_do_incant(t_player *player)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pic(msg, player);
  return (msg);
}

char		*grp_incant_done(t_player *player, int res)
{
  t_player	*pl;
  t_list	*list;
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pie(msg, player, res);
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

  msg = xmalloc(2 * sizeof(char));
  msg = pex(msg, player);
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
  char		*msg;
  
  msg = xmalloc(2 * sizeof(char));
  msg = pbc(msg, player, broad);
  return (msg);
}
