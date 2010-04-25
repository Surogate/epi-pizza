/*
** server_eat.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 16:46:57 2010 francois1 ancel
** Last update Fri Apr 16 16:46:57 2010 francois1 ancel
*/

#ifndef SERVER_EAT_C_INCLUDED
# define SERVER_EAT_C_INCLUDED

int		create_eat(t_svr_vector *vec, int player_id);
int		server_eat(t_svr_vector *vec, t_packet *pak, t_game *game);
int		delete_eat(t_svr_vector *vec, int player_id);

#endif
