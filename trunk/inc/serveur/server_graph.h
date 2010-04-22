/*
** server_graph.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 20 13:58:41 2010 francois1 ancel
** Last update Tue Apr 20 13:58:41 2010 francois1 ancel
*/

#ifndef SERVER_GRAPH_C_INCLUDED
# define SERVER_GRAPH_C_INCLUDED

void		new_gh(t_svr_vector *vec, t_client *cli, t_game *game);
void		gh_broad(t_svr_vector *vec, char *str);
void		gh_fct(t_svr_vector *vec, t_game *game, 
		       int player_id, char *(*fct)());

#endif
