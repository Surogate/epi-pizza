/*
**   Header
*/

#ifndef		__GAME_MOVE_H__
# define	__GAME_MOVE_H__

void		try_turn_left(t_packet *packet, t_player *player);
void		try_turn_right(t_packet *packet, t_player *player);
void		try_move(t_packet *packet, t_player *player);

#endif		/*__GAME_MOVE_H__*/
