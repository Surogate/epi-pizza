/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/

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

void		player_connect(t_game *game, char **av)
{

}

void		player_pos(t_game *game, char **av)
{

}

void		player_level(t_game *game, char **av)
{

}

void		player_invent(t_game *game, char **av)
{

}

void		player_expusle(t_game *game, char **av)
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

}

void		game_over(t_game *game, char **av)
{

}

void		server_msg(t_game *game, char **av)
{

}

void		wrong_func(t_game *game, char **av)
{

}

void		bad_param(t_game *game, char **av)
{

}

t_msg		mgs_lst[]=
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
