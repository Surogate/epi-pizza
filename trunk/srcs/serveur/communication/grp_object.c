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

char		*grp_get_object(t_player *player, int obj)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pgt(msg, player, obj);
  msg = pin(msg, player);  
  msg = bct(msg, player->pos);
  return (msg);
}

char		*grp_drop_object(t_player *player, int obj)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pdr(msg, player, obj);
  msg = pin(msg, player);  
  msg = bct(msg, player->pos);
  return (msg);
}
