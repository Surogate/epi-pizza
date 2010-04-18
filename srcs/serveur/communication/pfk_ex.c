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

char		*pfk(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 13, "%spdr %i \n", msg, player->player_id);
  return (msg);
}

char		*enw(char *msg, t_player *player, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 49) * sizeof(char));
  snprintf(msg, strlen(msg) + 48, "%senw %i %i% i %i\n", msg, egg->id, 
	   player->player_id, player->pos->x, player->pos->y);
  return (msg);
}

char		*eht(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 12, "%seht %i\n", msg, egg->id);
  return (msg);
}

char		*ebo(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 12, "%sebo %i\n", msg, egg->id);
  return (msg);
}

char		*edi(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 12, "%sedi %i\n", msg, egg->id);
  return (msg);
}
