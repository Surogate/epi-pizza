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

char		*sgt(char *msg, t_game *game)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "sgt %i\n", game->server.delay);
  return (msg);
}

char		*seg(char *msg, int win_team)
{
  msg = xrealloc(msg, (strlen(msg) + 15) * sizeof(char));
  snprintf(msg + strlen(msg), 15, "seg %i\n", win_team);
  return (msg);
}

char		*smg(char *msg, char *serv_msg)
{
  msg = xrealloc(msg, (strlen(msg) + strlen(serv_msg) + 5) * sizeof(char));
  snprintf(msg + strlen(msg), 13, "smg %s\n", serv_msg);
  return (msg);
}

char		*suc(char *msg)
{
  msg = xrealloc(msg, (strlen(msg) + 4) * sizeof(char));
  snprintf(msg + strlen(msg), 4, "suc\n");
  return (msg);
}

char		*sbp(char *msg)
{
  msg = xrealloc(msg, (strlen(msg) + 3) * sizeof(char));
  snprintf(msg + strlen(msg), 3, "bp\n");
  return (msg);
}
