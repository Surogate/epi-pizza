/*
** instruction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Tue Apr  6 15:01:49 2010 Florian Chanioux
** Last update Sat Apr 24 05:54:11 2010 Florian Chanioux
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "serveur/define.h"
#include "my_list.h"
#include "serveur/t_struct.h"
#include "serveur/t_packet.h"
#include "serveur/t_game_stc.h"
#include "serveur/game_cmd.h"
#include "serveur/response.h"
#include "serveur/count_player.h"
#include "serveur/server_born.h"
#include "serveur/server_ending.h"

t_inst		tab_instr[NB_INST] =
{
  {"avance", try_move, 7},
  {"droite", try_turn_right, 7},
  {"gauche", try_turn_left, 7},
  {"voir", try_view, 7},
  {"inventaire", try_invent, 1},
  {"prend", try_take_obj, 7},
  {"pose", try_drop_obj, 7},
  {"expulse", try_expulse, 7},
  {"broadcast",broadcast, 7},
  {"incantation", try_incant, 300},
  {"fork", try_fork, 42},
  {"connect_nbr", find_connect_nbr, 1}
};

int		find_elem(t_packet *ref, t_player *data)
{
  if (ref->player_id == data->player_id)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

void		treatment_intr(t_game *game, t_packet *packet)
{
  int		i;
  t_player	*player;

  i = -1;
  player = (t_player *)my_l_find(game->player, packet, find_elem);
  while (++i < NB_INST)
    {
      if (!strncmp(packet->av[0], tab_instr[i].inst, strlen(packet->av[0])))
	tab_instr[i].ptr_func(packet, player, game);
    }
}

int		treatment_duration(t_packet *packet)
{
  int		i;

  i = -1;
  while (++i < NB_INST)
    {
      if (!strncmp(packet->av[0], tab_instr[i].inst, strlen(packet->av[0])))
	{
	  packet->duration = tab_instr[i].delay;
	  return (EXIT_SUCCESS);
	}
    }
  packet->duration = 0;
  return (EXIT_FAILURE);
}

int		authent(t_game *game, t_packet *packet)
{
  t_team	*tmp;
  int		i;
  int		num;

  tmp = game->server.teamname;
  i = 0;
  if (!strcmp("GRAPHIC", packet->av[0]))
    return (-1);
  while (tmp)
    {
      num = game->server.nb_client - count_player(game, i);
      if (!strcmp(tmp->team, packet->av[0]) && num > 0)
	{
	  auth_ok(packet, num - 1, game);
	  return (player_born(game, packet->player_id, i));
	}
      tmp = tmp->next;
      ++i;
    }
  return (auth_fail(packet));
}
