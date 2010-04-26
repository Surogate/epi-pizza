/*
** server_born.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 15:15:31 2010 francois1 ancel
** Last update Sun Apr 18 12:20:33 2010 pierre1 boutbel
*/

#ifndef		SERVER_INSERT_PLAYER_C_INCLUDED
# define	SERVER_INSERT_PLAYER_C_INCLUDED

t_player	*create_player(int player_id, int team);
t_player	*init_player(t_game *game, int player_id, int team, 
			     t_svr_vector *vec);
t_player	*insert_player(t_game *game, t_player *player, int y, int x);
t_player	*rm_player(t_game *game, int id_player);


#endif		/*SERVER_INSERT_PLAYER_C_INCLUDED*/
