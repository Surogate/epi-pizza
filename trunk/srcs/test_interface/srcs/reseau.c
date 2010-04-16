/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/

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
