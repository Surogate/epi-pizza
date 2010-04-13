/*
** instruction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Tue Apr  6 15:01:49 2010 Florian Chanioux
** Last update Mon Apr 12 19:19:48 2010 Florian Chanioux
*/

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "t_packet.h"
#include "t_game_stc.h"
#include "game_cmd.h"

t_inst		tab_instr[NB_INST] =
{
  {"avance", try_move, 7},
  {"droite", try_turn_right, 7},
  {"gauche", try_turn_left, 7},
  {"voir", try_view, 7},
  {"inventaire", try_invent, 1},
  {"prendre", try_take_obj, 7},
  {"pose", try_drop_obj, 7},
  {"expulse", try_expulse, 7},
  {"broadcat",broadcast, 7},
  {"incant", try_incant, 300},
  {"fork", try_fork, 42},
  {"connect", connect, 0}
};

int		find_elem(void *ref, void *test)
{
  int		tmp;

  tmp = (int)ref;
  test = test;
  printf("%i\n", tmp);
  return (1);
}
/*
  Bordel elle sert a quoi cette fonction !!!
  A quoi ca sert une fonction qui caste une adresse en int ?
  pourquoi elle s'appelle "find_elem" alors qu'elle cherche rien ?
*/

void		treatment_intr(t_game *game, t_packet *packet)
{
  int		i;
  t_player	*player;

  i = -1;
  player = (t_player *)my_l_find(game->player,
				 (void *)(packet->player_id),
				 find_elem);
  while (++i < NB_INST)
    if (!strcmp(packet->av[0], tab_instr[i].inst))
    {
      tab_instr[i].ptr_func(packet, player);
      break;
    }
  if (!strcmp(packet->av[0], "fork"))
    do_fork(game, player);
}

int		treatment_duration(t_game *game, t_packet *packet)
{
  int		i;

  i = -1;
  while (++i < NB_INST)
    if (!strcmp(packet->av[0], tab_instr[i].inst))
    {
      packet->duration = tab_instr[i].delay * game->server.delay;
      return (EXIT_SUCCESS);
    }
  packet->duration = 0;
  return (EXIT_FAILURE);
}

