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

char		*sgt(char *msg, t_game *game)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 13, "%ssgt %i\n", msg, game->server.delay);
  return (msg);
}

char		*seg(char *msg, int win_team)
{
  msg = xrealloc(msg, (strlen(msg) + 13) * sizeof(char));
  snprintf(msg, strlen(msg) + 13, "%sseg %i\n", msg, win_team);
  return (msg);
}

char		*smg(char *msg, char *serv_msg)
{
  msg = xrealloc(msg, (strlen(msg) + strlen(serv_msg) + 2) * sizeof(char));
  snprintf(msg, strlen(msg) + 13, "%ssmg %s\n", msg, serv_msg);
  return (msg);
}

char		*suc(char *msg)
{
  msg = xrealloc(msg, (strlen(msg) + 4) * sizeof(char));
  snprintf(msg, strlen(msg) + 4, "%ssuc\n", msg);
  return (msg);
}

char		*sbp(char *msg)
{
  msg = xrealloc(msg, (strlen(msg) + 4) * sizeof(char));
  snprintf(msg, strlen(msg) + 4, "%sbp\n", msg);
  return (msg);
}
