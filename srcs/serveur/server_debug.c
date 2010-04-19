/*
** server_debug for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 09:15:22 2010 francois1 ancel
** Last update Fri Apr 16 09:15:22 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "t_packet.h"

void		debug_packet(t_packet *pak)
{
  fprintf (stderr, "========\n");
  if (pak)
    fprintf(stderr, "player id : %i\ntype : %i\nac : %i\ntime %i\nduration : %i\n", pak->player_id, pak->type, pak->ac, (int)pak->end.tv_sec, pak->duration);
  else
    fprintf(stderr, "pak non allouer\n");
  fprintf(stderr, "========\n");
}
