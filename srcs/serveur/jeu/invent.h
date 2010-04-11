/*
**  Header
*/

#ifndef		__GAME_INVENT_H__
# define	__GAME_INVENT_H__

void		try_drop_obj(t_packet *packet, t_player *player);
void		try_take_obj(t_packet *packet, t_player *player);
void		try_invent(t_packet *packet, t_player *player);

#endif		/*__GAME_INVENT_H__*/
