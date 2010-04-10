/*
**
*/

#include		<string.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		"pars_option.h"
#include		"t_struct.h"

void			puterr(char *str, int quit)
{
  if (write(2, str, strlen(str)) == -1 || quit == 1)
    exit(EXIT_FAILURE);
}

t_opt			*parser(int ac, char **av)
{
  t_opt			*opt;
  t_team		*team;
  int			i;
  
  i = 0;
  if ((team = malloc(sizeof(*team))) == NULL)
    puterr("Unable to malloc", 1);
  team->next = 0;
  if ((opt = malloc(7 * sizeof(*opt))) == NULL)
    puterr("Unable to malloc", 1);
  init_opt(opt, team);
  parse_option(opt, ac, av);
  return (opt);
}

void			fill_server(t_opt *opt, t_server *server)
{
  server->port = opt[0].value;
  server->height = opt[1].value;
  server->width = opt[2].value;
  server->teamname = opt[3].team;
  server->nb_client = opt[4].value;
  server->delay = opt[5].value;
}

void			check(int ac, char **av, t_server *server)
{
  t_opt			*opt;

  opt = parser(ac, av);
  fill_server(opt, server);
}

