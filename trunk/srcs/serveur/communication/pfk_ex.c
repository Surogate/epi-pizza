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
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "pdr %i\n", player->player_id);
  return (msg);
}

char		*enw(char *msg, int player_id, t_eggs *egg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 48) * sizeof(char));
  snprintf(msg + xstrlen(msg), 48, "enw %i %i% i %i\n", egg->id, player_id,
	   egg->pos->x, egg->pos->y);
  return (msg);
}

char		*eht(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "eht %i\n", egg->id);
  return (msg);
}

char		*ebo(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "ebo %i\n", egg->id);
  return (msg);
}

char		*edi(char *msg, t_eggs *egg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "edi %i\n", egg->id);
  return (msg);
}
