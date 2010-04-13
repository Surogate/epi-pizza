/*
** server_free.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 13 12:00:53 2010 Florian Chanioux
** Last update Tue Apr 13 13:38:49 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"

void		free_map(t_game *game)
{
  int		y;


  y = 0;
  while (y < game->server.height)
  {
    free(game->map[y]);
    y++;
  }
  free(game->map);
}
