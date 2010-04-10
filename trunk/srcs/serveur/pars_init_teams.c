/*
**
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		"t_struct.h"
#include		"pars_display.h"
#include		"pars_main.h"

void			create_new_team(t_opt *opt, char *team_name)
{
  static int		first = 0;
  t_team		*new;
  t_team		*cur;

  cur = opt[3].team;
  if ((new = malloc(sizeof(*new))) == NULL)
    puterr("Unable to malloc\n", 1);
  if (first)
    while (cur->next != 0)
      cur = cur->next;
  if ((new->team = malloc((strlen(team_name) + 1) * sizeof(*team_name))) == NULL)
    puterr("Unable to malloc\n", 1);
  new->team = strcpy(new->team, team_name);
  if (!first)
    {
      opt[3].team = new;
      opt[3].team->next = 0;
    }
  else
    {
      new->next = 0;
      cur->next = new;
    }
  first++;
}

void			init_teams(t_opt *opt, char **av, int ac, int *i)
{
  int			flag;

  flag = 0;
  *i += 1;
  while (*i < ac && av[*i][0] != '-')
    {
      create_new_team(opt, av[*i]);
      flag = 1;
      *i += 1;
    }
  if (!flag)
    put_usage(av[*i]);
  *i -= 1;
}

