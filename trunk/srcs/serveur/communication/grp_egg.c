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

  msg = pfk(NULL, player);
  return (msg);
}

char		*grp_fork_end(t_player *player, t_eggs *egg)
{
  char		*msg;

  msg = enw(NULL, player->player_id, egg);
  return (msg);
}

char		*grp_egg_hatch(t_eggs *egg)
{
  char		*msg;

  msg = eht(NULL, egg->id);
  return (msg);
}

char		*grp_egg_die(t_eggs *egg)
{
  char		*msg;

  msg = edi(NULL, egg);
  return (msg);  
}
