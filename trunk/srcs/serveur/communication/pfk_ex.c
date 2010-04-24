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
#include	"xfunc.h"

char		*pfk(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "pdr %i\n", player->player_id);
  return (msg);
}

char		*enw(char *msg, t_player *player, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 48) * sizeof(char));
  snprintf(msg + strlen(msg), 48, "enw %i %i% i %i\n", egg->id, 
	   player->player_id, player->pos->x, player->pos->y);
  return (msg);
}

char		*eht(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "eht %i\n", egg->id);
  return (msg);
}

char		*ebo(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "ebo %i\n", egg->id);
  return (msg);
}

char		*edi(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "edi %i\n", egg->id);
  return (msg);
}
