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

char		*ppo(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 40) * sizeof(char));
  snprintf(msg, strlen(msg) + 39, "%sppo %i %i %i %i\n", msg, 
	   player->player_id, player->pos->x, player->pos->y, player->dir + 1);
  return (msg);
}

char		*plv(char *msg, t_player *player)
{
  msg = xrealloc(msg, (strlen(msg) + 18) * sizeof(char));
  snprintf(msg, strlen(msg) + 17, "%splv %i %i\n", msg, player->player_id, 
	   player->level);
  return (msg);
}

char		*pin(char *msg, t_player *player)
{
  int		i;

  i = -1;
  msg = xrealloc(msg, (strlen(msg) + 115) * sizeof(char));
  snprintf(msg, strlen(msg) + 4, "%splv %i %i %i", msg, player->player_id, 
	   player->pos->x, player->pos->y);
  while (++i != RESS_NUM)
    snprintf(msg, 114, "%s %i", msg, player->ress[i]);
  snprintf(msg, 114, "%s\n", msg);
  return (msg);
}
