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

char		*bct(char *msg, t_map *map)
{
  int           i;

  i = -1;
  msg = xrealloc(msg, (strlen(msg) + 115) * sizeof(char));
  snprintf(msg, strlen(msg) + 4, "%sbct %i %i", msg, map->x, map->y);
  while (++i != RESS_NUM)
    snprintf(msg, 114, "%s %i", msg, map->cas.ress[i]);
  snprintf(msg, 114, "%s\n", msg);
  return (msg);
}
