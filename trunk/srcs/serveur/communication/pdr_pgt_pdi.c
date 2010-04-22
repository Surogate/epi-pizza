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
#include	"xfunc.h"

char		*pdr(char *msg, t_player *player, int ress)
{
  msg = xrealloc(msg, (strlen(msg) + 26) * sizeof(char));
  snprintf(msg + strlen(msg), 26, "pdr %i %i\n", player->player_id, 
	   ress);
  return (msg);
}

char		*pgt(char *msg, t_player *player, int ress)
{
  msg = xrealloc(msg, (strlen(msg) + 26) * sizeof(char));
  snprintf(msg + strlen(msg), 26, "pgt %i %i\n", player->player_id, 
	   ress);
  return (msg);
}

char		*pdi(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "pgi %i\n", player->player_id);
  return (msg);
}
