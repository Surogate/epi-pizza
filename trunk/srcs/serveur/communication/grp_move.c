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

char		*grp_move(t_player *player)
{
  char		*msg;

  msg = xmalloc(sizeof(char));
  msg = ppo(msg, player);
  return (msg);
}
