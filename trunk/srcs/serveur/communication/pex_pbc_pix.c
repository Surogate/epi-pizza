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

char		*pex(char *msg, t_player *player)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "pex %i\n", player->player_id);
  return (msg);
}

char		*pbc(char *msg, t_player *player, char *broad)
{
  msg = xrealloc(msg, (xstrlen(msg) + 16 + xstrlen(broad)) * sizeof(char));
  snprintf(msg + xstrlen(msg), 16 + xstrlen(broad), "pbc %i %s\n",
	   player->player_id, broad);
  return (msg);
}

char		*pie(char *msg, t_player *player, int res)
{
  msg = xrealloc(msg, (xstrlen(msg) + 37) * sizeof(char));
  snprintf(msg + xstrlen(msg), 37, "pie %i %i %i\n", player->pos->x,
	   player->pos->y, res);
  return (msg);
}

char		*pic(char *msg, t_player *player)
{
  t_player	*pl;
  t_list	*list;

  msg = xrealloc(msg, (xstrlen(msg) + 39) * sizeof(char));
  snprintf(msg + xstrlen(msg), 28, "pic %i %i %i", player->pos->x,
	   player->pos->y, player->level);
  list = player->pos->cas.player;
  while (list->data != NULL)
    {
      pl = (t_player*)list->data;
      msg = xrealloc(msg, (xstrlen(msg) + 11) * sizeof(char));
      snprintf(msg + xstrlen(msg), 11, " %i", pl->player_id);
      list = list->next;
    }
  snprintf(msg + xstrlen(msg), 2, "\n");
  return (msg);
}
