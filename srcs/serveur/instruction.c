/*
** instruction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr  6 15:01:49 2010 Florian Chanioux
** Last update Sat Apr 10 18:47:27 2010 pierre1 boutbel
*/

#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "server.h"

# define	NB_INST		(12)

t_instr		tab_instr[NB_INST] =
{
  {"avance", try_move},
  {"droite", try_turn_right},
  {"gauche", try_turn_left},
  {"voir", try_view},
  {"inventaire", try_invent},
  {"prendre", try_take_obj},
  {"pose", try_drop_obj},
  {"expulse", try_expulse},
  {"broadcat",broadcast},
  {"incant", try_incant},
  {"fork", try_fork},
  {"connect", connect},
  {NULL, NULL}
};

int		find_elem(void *ref, void *test)
{
  int		tmp;

  temp = (int)ref;
  printf("%i\n", temp);
  return (1);
}

void		treatment_intr(t_game *game, t_packet *packet)
{
  int		i;

  i = -1;
  while (++i < NB_INST)
    if (strcmp(packet->av[0], tab_instr[i].inst))
    {
      player = (t_player *)my_l_find(game->player,
				     (void *)(packet->player_id),
				     find_elem());
      tab_instr[i].ptr_func(packet, player);
      break;
    }
  if (strcmp(packet->av[0], "fork"))
    do_fork(game, player);
}
