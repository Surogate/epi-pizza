/*
** server_plaction.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 17 13:45:23 2010 francois1 ancel
** Last update Sat Apr 17 13:45:23 2010 francois1 ancel
*/

#ifndef SERVER_PLACTION_C_INCLUDED
# define SERVER_PLACTION_C_INCLUDED

int			find_act_fct(t_packet *in, int *player_id);
int			create_plaction(t_svr_vector *vec, t_client *cli,
					t_game *game);
int			exec_plaction(t_svr_vector *vec, t_packet *pak,
				      t_game *game);
int			delete_plaction(t_svr_vector *vec, int player_id);

#endif
