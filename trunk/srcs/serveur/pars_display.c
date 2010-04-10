/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Sat Apr 10 15:11:57 2010 francois1 ancel
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>

#include		"my_list.h"
#include		"define.h"
#include		"t_struct.h"
#include		"pars_main.h"
#include		"pars_define.h"

void			put_usage(char *opt)
{
  fprintf(stderr, INVAL_OPT);
  fprintf(stderr, "%s\n", opt);
  fprintf(stderr, "\033[7m\033[1mZAPPY HELPER 0.1\033[m :");
  fprintf(stderr, " Zappy Server 0.1 Available Args\033[m\n"); 
  fprintf(stderr, "usage: ./zappy [options]\n");
  fprintf(stderr, HELP_OPT1);
  fprintf(stderr, HELP_OPT2);
  fprintf(stderr, HELP_OPT3);
  fprintf(stderr, HELP_OPT4);
  fprintf(stderr, HELP_OPT5);
  fprintf(stderr, HELP_OPT6);
  exit(EXIT_FAILURE);
}

void			display_values(t_server *server, t_team *team)
{
  int			i;

  i = 1;
  printf("\n\033[1;31m/***************Server Infos***************/\033[m\n\n");
  printf("\033[1;32mServer Port\033[m -> %d\n", server->port);
  printf("\033[1;32mMap height\033[m  -> %d\n", server->height);
  printf("\033[1;32mMap width\033[m   -> %d\n", server->width);
  printf("\033[1;32mTeams Name\033[m :\n");
  if (!strcmp(team->team, STD_TEAM_NAME))
    printf("\t1 : %s\n", STD_TEAM_NAME);
  else
    while (team != 0)
      {
	printf("\t%d : %s\n", i, team->team);
	i++;
	team = team->next;
      }
  printf("\033[1;32mNb client\033[m   -> %d\n", server->nb_client);
  printf("\033[1;32mTime delay\033[m  -> %d\n\n", server->delay);
}

