/*
**  Header
*/

#ifndef		__PROTO_ACTIONS_H__
# define	__PROTO_ACTIONS_H__

/*action.c*/
void		player_expulse(t_game *game, char **av);
void		player_broadcast(t_game *game, char **av);
void		incant(t_game *game, char **av);
void		end_incant(t_game *game, char **av);
void		player_fork(t_game *game, char **av);

/*com_serveur.c*/
void		time_unite(t_game *game, char **av);
void		game_over(t_game *game, char **av);
void		server_msg(t_game *game, char **av);

/*egg.c*/
void		eggs_drop(t_game *game, char **av);
void		eggs_ready(t_game *game, char **av);
void		eggs_to_player(t_game *game, char **av, int ac);
void		eggs_die(t_game *game, char **av, int ac);

/*info_player.c*/
void		change_player_pos(t_game *game, char **av, t_pos pos, 
				  int p_id);
void		player_pos(t_game *game, char **av);
void		player_level(t_game *game, char **av);
void		player_invent(t_game *game, char **av);
void		player_die(t_game *game, char **av);

/*init_info.c*/
void		init_map(t_game *game, char **av);
void		put_to_case(t_game *game, char **av);
void		team_name(t_game *game, char **av);
void		player_connect(t_game *game, char **av);

/*object.h*/
void		drop_item(t_game *game, char **av);
void		take_item(t_game *game, char **av);

/*common_func.c*/
t_player	*find_player(t_game *game, int id_player);

#endif		/*__PROTO_ACTIONS_H__*/
