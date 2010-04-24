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

char		*msz(char *msg, t_game *game)
{
  msg = xrealloc(msg, (strlen(msg) + 27) * sizeof(char));
  snprintf(msg + strlen(msg), 26, "msz %i %i\n", game->server.width,
	   game->server.height);
  return (msg);
}

char		*tna(char *msg, t_game *game)
{
  t_team	*team;

  team = game->server.teamname;
  while (team != NULL)
    {
      msg = xrealloc(msg, (strlen(msg) + strlen(team->team) + 6) *
		     sizeof(char));
      snprintf(msg + strlen(msg), strlen(team->team) + 6, "tna %s\n",
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
  while ((team != NULL) && (player->team != ++count))
    team = team->next;
  if (team != NULL)
    {
      msg = xrealloc(msg, (strlen(msg) + 61 + strlen(team->team)) *
		     sizeof(char));
      snprintf(msg + strlen(msg), 61 + strlen(team->team),
	       "pnw %i %i %i %i %i %s\n", player->player_id,
	       player->pos->x, player->pos->y, player->dir + 1, 
	       player->level, team->team);
    }
  return (msg);
}
