/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/
#include	<stdio.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		init_map(t_game *game, char **av)
{
  int		ac;

  ac = 0;
  while (av[ac])
    ac++;
  if (ac > 2)
    if (atoi(av[1]) && atoi(av[2]))
      {
	game->info.size_w = atoi(av[1]);
	game->info.size_h = atoi(av[2]);
      }
}

void		put_to_case(t_game *game, char **av)
{
  int		ac;
  int		x;
  int		y;
  int		n_obj;

  ac = 0;
  while (av[ac])
    ac++;
  if (ac > 10)
    {
      x = atoi(av[1]);
      y = atoi(av[2]);
      n_obj = 0;
      while (n_obj < 7)
	{
	  game->map.t_case[y][x].obj[n_obj] = atoi(av[3 + n_obj]);
	  n_obj++;
	}
    }
}

void		team_name(t_game *game, char **av)
{

}

t_player	*new_player(char **av)
{
  t_player	*player;

  player = 0;
  player = xmalloc(sizeof(*player));
  if (player)
    {
      player->id = atoi(&av[1][1]);
      player->pos.x = atoi(av[2]);
      player->pos.y = atoi(av[3]);
      player->sens = atoi(av[4]);
      player->lv = atoi(av[5]);
      strcpy(player->team, av[6]);
      player->next_pc = 0;
      player->next_pg = 0;
    }
  return (player);
}

void		player_connect(t_game *game, char **av)
{
  t_player	*player;
  t_player	*temp;

  player = game->player;
  if (player)
    {
      while (player->next_pg)
	player = player->next_pg;
      player->next_pg = new_player(av);
      player = player->next_pg;
    }
  else
    {
      game->player = new_player(av);
      player = game->player;
    }
  if (player)
    {
      temp = game->map.t_case[player->pos.y][player->pos.x].player;
      if (temp)
	{
	  while (temp->next_pc)
	    temp = temp->next_pc;
	  temp->next_pc = player;
	}
      else
	game->map.t_case[player->pos.y][player->pos.x].player = player;
    }
}

void		player_pos(t_game *game, char **av)
{

}

void		player_level(t_game *game, char **av)
{
  t_player	*player;

  player = game->player;
  if (player)
    {
      while (player->next_pg && player->id != atoi(&av[1][1]))
	player = player->next_pg;
      if (player->id == atoi(&av[1][1]))
	player->lv = atoi(av[2]);
    }
}

void		player_invent(t_game *game, char **av)
{
  t_player	*player;
  int		n_obj;

  player = game->player;
  if (player)
    {
      while (player->next_pg && player->id != atoi(&av[1][1]))
	player = player->next_pg;
      if (player->id == atoi(&av[1][1]))
	{
	  n_obj = 0;
	  while (n_obj < 7)
	    {
	      player->inventaire[n_obj] = atoi(av[4 + n_obj]);
	      n_obj++;
	    }
	}
    }
}

void		player_expulse(t_game *game, char **av)
{

}

void		player_broadcast(t_game *game, char **av)
{

}

void		incant(t_game *game, char **av)
{

}

void		end_incant(t_game *game, char **av)
{

}

void		player_fork(t_game *game, char **av)
{

}

void		drop_item(t_game *game, char **av)
{

}

void		take_item(t_game *game, char **av)
{

}

void		player_die(t_game *game, char **av)
{

}

void		eggs_drop(t_game *game, char **av)
{

}

void		eggs_ready(t_game *game, char **av)
{

}

void		eggs_to_player(t_game *game, char **av)
{

}

void		eggs_die(t_game *game, char **av)
{

}

void		time_unite(t_game *game, char **av)
{
  game->info.time = av[1];
}

void		game_over(t_game *game, char **av)
{
  game = game;
  if (av[1])
    printf("GAME OVER!\nTEAM %s WIN!", av[1]);
}

void		server_msg(t_game *game, char **av)
{

}

void		wrong_func()
{
  printf("Unkwon function!\n");
}

void		bad_param()
{
  printf("bad param!\n");
}

t_msg		mgs_lst[] =
  {
    {"msz", init_map},
    {"bct", put_to_case},
    {"tna", team_name},
    {"pnw", player_connect},
    {"ppo", player_pos},
    {"plv", player_level},
    {"pin", player_invent},
    {"pex", player_expulse},
    {"pbc", player_broadcast},
    {"pic", incant},
    {"pie", end_incant},
    {"pfk", player_fork},
    {"pdr", drop_item},
    {"pgd", take_item},
    {"pdi", player_die},
    {"enw", eggs_drop},
    {"eht", eggs_ready},
    {"ebo", eggs_to_player},
    {"edi", eggs_die},
    {"sgt", time_unite},
    {"seg", game_over},
    {"smg", server_msg},
    {"suc\n", wrong_func},
    {"sbp\n", bad_param},
    {0,0}
  };
