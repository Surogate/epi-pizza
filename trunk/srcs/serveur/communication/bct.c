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
  msg = xrealloc(msg, (strlen(msg) + 116) * sizeof(char));
  snprintf(msg + strlen(msg), 4, "bct %i %i", map->x, map->y);
  while (++i != RESS_NUM)
    snprintf(msg + strlen(msg), 11, " %i", map->cas.ress[i]);
  snprintf(msg + strlen(msg), 2, "\n");
  return (msg);
}
