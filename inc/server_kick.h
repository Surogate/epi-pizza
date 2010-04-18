/*
** server_kick.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 16:03:15 2010 francois1 ancel
** Last update Thu Apr 15 16:03:15 2010 francois1 ancel
*/

#ifndef SERVER_KICK_C_INCLUDED
# define SERVER_KICK_C_INCLUDED

int		find_kick_fct(t_packet *in, int *player_id);
int		create_kick(t_svr_vector *vec, t_select *slt,
			    int player_id, int time);
int		server_kick(t_svr_vector *vec, t_select *slt_par, 
			    int player_id, t_game *game);
void		delete_kick(t_svr_vector *vec, int player_id);

#endif
