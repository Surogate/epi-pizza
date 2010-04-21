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
#include	"communication.h"
#include	"xfunc.h"

static char	*print_player(char *msg, t_game *game)
{
  t_player	*player;
  t_list	*list;

  list = game->player;
  while (list->data != NULL)
    {
      player = (t_player *)list->data;
      msg = pnw(msg, player, game);
      list = list->next;
    }
  return (msg);
}

/*
static char	*print_eggs(char *msg, t_player *player, t_game *game)
{
  t_list	*list;
  t_eggs	*egg;
  
  list = game->eggs;
  while (list->data != NULL)
    {
      egg = (t_eggs *)list->data;
      msg = enw(msg, player, egg);
      list = list->next;
    }
  return (msg);
}
*/

char		*grp_connex_monit(t_game *game)
{
  int		x;
  int		y;
  char		*msg;

  msg = xmalloc(sizeof(char));
  msg = msz(msg, game);
  x = -1;
  while (++x != game->server.height)
    {
      y = -1;
      while (++y != game->server.width)
	msg = bct(msg, &(game->map[x][y]));
    }
  msg = tna(msg, game);
  msg = print_player(msg, game);

  /*FAUT IL SAUVEGARDER QUI A PONDU L'OEUF ?????????*/

  /*  msg = print_eggs(msg, game);*/

  return (msg);
}

char		*grp_connex_player(t_game *game, t_player *player)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = pnw(msg, player, game);
  return (msg);
}

char		*grp_connex_zombie(t_game *game, t_player *player, t_eggs *egg)
{
  char		*msg;

  msg = xmalloc(2 * sizeof(char));
  msg = ebo(msg, egg);
  msg = pnw(msg, player, game);
  return (msg);
}
