/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Sat Apr 10 15:11:57 2010 francois1 ancel
*/

#include		<string.h>
#include		<stdlib.h>

#include		"my_list.h"
#include		"define.h"
#include		"pars_init_teams.h"
#include		"pars_display.h"
#include		"pars_main.h"
#include		"t_struct.h"
#include		"pars_define.h"

void			malloc_team(t_opt *opt)
{
  if ((opt[3].team->team = malloc(strlen(STD_TEAM_NAME) * 
				  sizeof(*(opt[3].team->team)))) == NULL)
    puterr("Unable to malloc -> Struct Team\n", 1);
}

void			init_opt(t_opt *opt, t_team *team)
{
  int			i;

  i = 0;
  while (i < 8)
    opt[i++].option = malloc(10 * sizeof(opt[0].option));
  opt[0].option = strcpy(opt[0].option, CHAR_OPT1);
  opt[0].value = VALUE_OPT1;
  opt[1].option = strcpy(opt[1].option, CHAR_OPT2);
  opt[1].value = VALUE_OPT2;
  opt[2].option = strcpy(opt[2].option, CHAR_OPT3);
  opt[2].value = VALUE_OPT3;
  opt[3].option = strcpy(opt[3].option, CHAR_OPT4);
  opt[3].value = VALUE_OPT4;
  opt[3].team = team;
  malloc_team(opt);
  opt[3].team->team = strcpy(opt[3].team->team, STD_TEAM_NAME);
  opt[3].team->lim = VALUE_OPT5;
  opt[4].option = strcpy(opt[4].option, CHAR_OPT5);
  opt[4].value = VALUE_OPT5;
  opt[5].option = strcpy(opt[5].option, CHAR_OPT6);
  opt[5].value = VALUE_OPT6;
  opt[6].option = strcpy(opt[6].option, CHAR_OPT7);
  opt[6].value = VALUE_OPT7;
  opt[7].value = 0;
  opt[7].option = 0;
}

int			isnum(char *str)
{
  int			i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

void			modif_struc(t_opt *opt, int ac, char **av, int *i)
{
  int			j;
  int			flag;

  flag = 1;
  j = 0;
  while (opt[j].option != 0 && flag)
    {
      if (!strcmp(opt[j].option, av[*i]))
	{
	  if (!strcmp(opt[j].option, "-n"))
	    init_teams(opt, av, ac, i);
	  else if ((*i + 1) < ac && av[*i + 1][0] != '-' && isnum(av[*i + 1]))
	    {
	      opt[j].value = atoi(av[*i + 1]);
	      *i += 1;;
	    }
	  else
	    put_usage(av[*i]);
	  flag = 0;
	}
      j++;
    }
  if (flag)
    put_usage(av[*i]);
}

void			parse_option(t_opt *opt, int ac, char **av)
{
  int			i;

  i = 1;
  while (i < ac)
    {
      modif_struc(opt, ac, av, &i);
      i++;
    }
}
