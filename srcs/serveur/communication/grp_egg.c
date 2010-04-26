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

char		*grp_fork(t_player *player)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pfk(msg, player);
  return (msg);
}

char		*grp_fork_end(t_player *player, t_eggs *egg)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = enw(msg, player->player_id, egg);
  return (msg);
}

char		*grp_egg_hatch(t_eggs *egg)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = eht(msg, egg);
  return (msg);
}

char		*grp_egg_die(t_eggs *egg)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = edi(msg, egg);
  return (msg);  
}
