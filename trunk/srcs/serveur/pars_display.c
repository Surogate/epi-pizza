/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Mon Apr 26 11:00:58 2010 pierre1 boutbel
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>

#include		"my_list.h"
#include		"xfunc.h"
#include		"serveur/define.h"
#include		"serveur/t_struct.h"
#include		"serveur/pars_main.h"
#include		"serveur/pars_define.h"

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

void			last_check(t_server *server)
{
  if (server->port == 0)
    {
      puterr("\n\033[1;31m!!! Warning \033[m: Port is out of range", 0);
      puterr(", redefining value to \033[1;31m4242\033[m\n", 0);
      server->port = 4242;
    }
  else if (server->port < 3000 || server->port > 65000)
    {
      puterr("\n\033[1;31mPort is out of range [3000 - 65000]\033[m\n\n", 0);
      put_usage(" -p");
    }
  if (server->width == 0 || server->height == 0)
    {
      puterr("\n\033[1mWidth/Height must be superior to 0\033[m\n\n", 0);
      put_usage(" -y/-x");
    }
}

void			display_values(t_server *server, t_team *team)
{
  int			i;

  i = 1;
  if (server->debug == 1)
    printf("\n\033[1;4;5;7;31m\t!!!!! WARNING : SERVER IN DEBUG MODE\033[m\n");
  printf("\n\033[1;31m/***************Server Infos***************/\033[m\n\n");
  printf("\033[1;32mServer Port\033[m -> %d\n", server->port);
  printf("\033[1;32mMap height\033[m  -> %d\n", server->height);
  printf("\033[1;32mMap width\033[m   -> %d\n", server->width);
  printf("\033[1;32mTeams Name\033[m :\n");
  if (!strncmp(team->team, STD_TEAM_NAME, xstrlen(STD_TEAM_NAME)))
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

