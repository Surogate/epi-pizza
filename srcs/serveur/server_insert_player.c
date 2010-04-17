/*
** server_insert_player.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 13 12:03:06 2010 Florian Chanioux
** Last update Fri Apr 16 18:30:23 2010 pierre1 boutbel
*/

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"
#include "t_packet.h"

t_player	*create_player(int player_id, int team)
{
  t_player	*player;
  int		i;

  player = xmalloc(sizeof(t_player));
  player->player_id = player_id;
  player->team = team;
  player->dir = 1 + rand() % 3;
  player->pos = NULL;
  player->ress[(i = 0)] = 10;
  while (++i < RESS_NUM)
    player->ress[i] = 0;
  return (player);
}

t_player	*init_player(t_game *game, int player_id, int team)
{
  int		x;
  int		y;
  t_player	*player;
  t_map		*cas;

  srand(time(NULL));
  y = rand() % game->server.height;
  x = rand() % game->server.width;
  player = create_player(player_id, team);
  cas = &(game->map[y][x]);
  player->pos = cas;
  cas->cas.player = my_l_insert(cas->cas.player, player);
  game->player = my_l_insert(game->player, player);
  generate_ress(game);
  return (player);
}

t_player	*insert_player(t_game *game, t_player *player,
			       int y, int x)
{
  struct s_map	*cas;

  srand(time(NULL));
  cas = &(game->map[y][x]);
  player->pos = cas;
  cas->cas.player = my_l_insert(cas->cas.player, player);
  game->player = my_l_insert(game->player, player);
  return (player);
}

int		find_player(t_player *ref, t_player *data)
{
  if (data && (ref->player_id == data->player_id))
    return (1);
  return (0);
}

t_player	*rm_player(t_game *game, int id_player)
{
  t_player	*player;
  int		i;

  player = (t_player *)my_l_find(game->player, &id_player, find_player);
  if (player)
    {
      i = -1;
      while (++i != RESS_NUM)
	(player->pos)->cas.ress[i] = (player->pos)->cas.ress[i] + player->ress[i];
      player->pos->cas.player = my_l_rm(player->pos->cas.player ,player, find_player);
      game->player = my_l_rm(game->player, player, find_player);
      supp_ress(game);
    }
  else
    printf("player %i pas trouver\n", id_player);
  return (player);
}

