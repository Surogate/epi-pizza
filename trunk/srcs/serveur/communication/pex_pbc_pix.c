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

char		*pex(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 16) * sizeof(char));
  snprintf(msg, strlen(msg) + 15, "%spex %i\n", msg, player->player_id);
  return(msg);
}

char		*pbc(char *msg, t_player *player, char *broad)
{
  msg = xrealloc(msg, (strlen(msg) + 16 + strlen(broad)) * sizeof(char));
  snprintf(msg, strlen(msg) + 15, "%spbc %i %s\n", msg, player->player_id,
	   broad);
  return(msg);
}

char		*pie(char *msg, t_player *player, int res)
{
  msg = xrealloc(msg, (strlen(msg) + 28) * sizeof(char));
  snprintf(msg, strlen(msg) + 28, "%spie %i %i %i\n", msg, player->pos->x, 
	   player->pos->y, res);
  return (msg);
}

char		*pic(char *msg, t_player *player)
{
  t_player	*pl;
  t_list	*list;

  msg = xrealloc(msg, (strlen(msg) + 39) * sizeof(char));
  snprintf(msg, strlen(msg) + 28, "%spic %i %i %i", msg, player->pos->x, 
	   player->pos->y, player->level);
  list = player->pos->cas.player;
  while (list->data != NULL)
    {
      pl = (t_player*)list->data;
      msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
      snprintf(msg, strlen(msg) + 12, "%s %i", msg, pl->player_id);
      list = list->next;
    }
  snprintf(msg, strlen(msg) + 1, "%s\n", msg);
  return (msg);
}

