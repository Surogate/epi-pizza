/*
** server_action.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 18:05:52 2010 francois1 ancel
** Last update Thu Apr 15 18:05:52 2010 francois1 ancel
*/

#ifndef SERVER_ACTION_C_INCLUDED
# define SERVER_ACTION_C_INCLUDED

int			sort_duration(t_packet *data, t_packet *strct);
int			player_id_find(t_packet *data, int *player_id);
int			execute_action(t_svr_vector *vec, t_game *game, 
				       t_select *slt_par);

#endif
