/*
** instruction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr  6 15:01:49 2010 Florian Chanioux
** Last update Fri Apr  9 13:59:47 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "t_svr_stc.h"
#include "t_struct.h"
#include "server.h"

# define	NB_INST		(12)

t_instr		tab_instr[NB_INST] =
{
  {"avance", try_avance},
  {"droite", trydroite},
  {"gauche",},
  {"voir",},
  {"inventaire",},
  {"prendre",},
  {"pose",},
  {"expulse",},
  {"broadcat",},
  {"incant",},
  {"fork",},
  {"connect",},
  {NULL, NULL}
};

void		treatment_intr(t_packet *packet)
{
  int		i;

  i = -1;
  while (i < NB_INST)
  {
    if (strcmp(packet->av[0], tab_instr[i].inst))
    {
      tab_instr[i].ptr_func(packet);
      break;
    }
  }
  
}
