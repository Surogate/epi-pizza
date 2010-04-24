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

char		*grp_player_die(t_player *player)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pdi(msg, player);
  return (msg);
}

char		*grp_party_end(int winner)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = seg(msg, winner);
  return (msg);  
}
