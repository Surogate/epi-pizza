/*
** response for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 13 12:24:14 2010 francois1 ancel
** Last update Tue Apr 13 12:24:14 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

#include "define.h"
#include "my_list.h"
#include "t_packet.h"
#include "t_struct.h"
#include "t_game_stc.h"

#define	AUTH_OK_SIZ 35
#define AUTH_FAIL_SIZ 4

int	auth_ok(t_packet *pak, int num_client, t_game *game)
{
  t_rep	*rep;

  pak->ac_rep = 1;
  pak->response = malloc(sizeof(*(pak->response)));
  if (pak->response)
    {
      rep = pak->response;
      rep[0].id_player = pak->player_id;
      rep[0].mess = malloc(AUTH_OK_SIZ * sizeof(*rep->mess));
      if (rep->mess)
	snprintf(rep->mess, AUTH_OK_SIZ, "%i\n%i %i\n", num_client,
		 game->server.width, game->server.height);
    }
  return (1);
}

int	auth_fail(t_packet *pak)
{
  t_rep	*rep;

  pak->ac_rep = 1;
  pak->response = malloc(sizeof(*(pak->response)));
  if (pak->response)
    {
      rep = pak->response;
      rep[0].id_player = pak->player_id;
      rep[0].mess = malloc(AUTH_FAIL_SIZ * sizeof(*(rep[0].mess)));
      if (rep[0].mess)
	snprintf(rep[0].mess, AUTH_FAIL_SIZ, "KO\n");
    }
  return (0);
}
