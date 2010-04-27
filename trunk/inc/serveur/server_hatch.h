/*
** server_hatch.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 20 18:24:42 2010 francois1 ancel
** Last update Tue Apr 20 18:24:42 2010 francois1 ancel
*/

#ifndef SERVER_HATCH_C_INCLUDED
# define SERVER_HATCH_C_INCLUDED

int		find_hatch_fct(t_packet *in, int *player_id);
int	       	create_hatch(t_svr_vector *vec, t_packet *tmp);
int	       	server_hatch(t_svr_vector *vec, t_packet *pak, t_game *game);
void		delete_hatch(t_svr_vector *vec, int player_id);
void		do_hatch(t_game *game, int id_egg, t_svr_vector *vec);

#endif
