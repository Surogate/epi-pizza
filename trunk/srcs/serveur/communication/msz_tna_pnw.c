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

char		*msz(char *msg, t_game *game)
{
  msg = xrealloc(msg, (strlen(msg) + 27) * sizeof(char));
  snprintf(msg, strlen(msg) + 26, "%smsz %i %i\n", msg, game->server.width,
	   game->server.height);
  return (msg);
}

char		*tna(char *msg, t_game *game)
{
  t_team	*team;

  team = game->server.teamname;
  while (team != NULL)
    {
      msg = xrealloc(msg, (strlen(msg) + strlen(team->team) + 1) * 
		     sizeof(char));
      snprintf(msg, strlen(msg) + strlen(team->team), "%stan %s\n", msg, 
	       team->team);
      team = team->next;
    }
  return (msg);
}

char		*pnw(char *msg, t_player *player, t_game *game)
{
  t_team	*team;
  int		count;
 
  count = -1;
  team = game->server.teamname;
  while (team != NULL && player->team != ++count)
    team = team->next;  

  if (team != NULL)
    {
      msg = xrealloc(msg, (strlen(msg) + 52 + strlen(team->team)) * 
		     sizeof(char));
      snprintf(msg, strlen(msg) + 51 + strlen(team->team) , 
	       "%spnw %i %i %i %i %i %s\n", msg, player->player_id,
	       player->pos->x, player->pos->y, player->dir + 1, player->level,
	       team->team);
    }
  return (msg);
}
