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

char		*grp_move(t_player *player)
{
  char		*msg;

  msg = xmalloc(sizeof(char));
  msg = ppo(msg, player);
  return (msg);
}
