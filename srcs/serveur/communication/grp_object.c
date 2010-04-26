/*
**  Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdarg.h>

#include	"serveur/define.h"
#include	"my_list.h"
#include	"serveur/t_struct.h"
#include	"serveur/communication.h"
#include	"xfunc.h"

char		*grp_get_object(t_player *player, int obj)
{
  char		*msg;

  msg = pgt(NULL, player, obj);
  msg = pin(msg, player);
  msg = bct(msg, player->pos);
  return (msg);
}

char		*grp_drop_object(t_player *player, int obj)
{
  char		*msg;

  msg = pdr(NULL, player, obj);
  msg = pin(msg, player);  
  msg = bct(msg, player->pos);
  return (msg);
}
