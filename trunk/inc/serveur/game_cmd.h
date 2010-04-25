/*
**  Header
*/

#ifndef		__GAME_CMD_H__
# define	__GAME_CMD_H__

/*concatene_msg_view.c*/
char		*add_player(t_vision *cur_case, char *msg);
char		*add_ressource(t_vision *cur_case, char *msg);
char		*explore_case(t_vision *cur_case, char *msg);
char		*concatene_msg(t_vision *list);

/*expulse.c*/
void		do_expulse(t_packet *packet, t_player *player);
void		try_expulse(t_packet *packet, t_player *player);

/*hatch.c*/
void		do_hatch(t_game *game, int id_egg);
void		do_fork(t_game *game, t_player *player);
void		try_fork(t_packet *packet, t_player *player);

/*incant.h*/
void		try_incant(t_packet *packet, t_player *player);

/*invent.h*/
void		try_drop_obj(t_packet *packet, t_player *player);
void		try_take_obj(t_packet *packet, t_player *player);
void		try_invent(t_packet *packet, t_player *player);

/*move.h*/
void		try_turn_left(t_packet *packet, t_player *player);
void		try_turn_right(t_packet *packet, t_player *player);
void		try_move(t_packet *packet, t_player *player);

/*view.h*/
void		try_view(t_packet *packet, t_player *player);

/*connect_nbr.h*/
void		find_connect_nbr(t_packet *packet, t_player *player,
				 t_game *game);

/*broadcast*/
void		broadcast(t_packet *packet, t_player *player);
void		expulse(t_packet *packet, t_player *player);
void		incant(t_packet *packet, t_player *player);
void		multi(t_packet *packet, t_player *player);
void		connect(t_packet *packet, t_player *player);

#endif		/*__GAME_CMD_H__*/

