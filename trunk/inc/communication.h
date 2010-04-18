/*
**  Header
*/

#ifndef		__COMMUNICATION_H__
# define	__COMMUNICATION_H__

char		*bct(char *msg, t_map *map);

char		*msz(char *msg, t_game *game);
char		*tna(char *msg, t_game *game);
char		*pnw(char *msg, t_player *player, t_game *game);

char		*pdr(char *msg, t_player *player, int ress);
char		*pgt(char *msg, t_player *player, int ress);
char		*pdi(char *msg, t_player *player);

char		*pex(char *msg, t_player *player);
char		*pbc(char *msg, t_player *player, char *broad);
char		*pie(char *msg, t_player *player, int res);
char		*pic(char *msg, t_player *player);

char		*pfk(char *msg, t_player *player);
char		*enw(char *msg, t_player *player, t_eggs *egg);
char		*eht(char *msg, t_eggs *egg);
char		*ebo(char *msg, t_eggs *egg);
char		*edi(char *msg, t_eggs *egg);

char		*ppo(char *msg, t_player *player);
char		*plv(char *msg, t_player *player);
char		*pin(char *msg, t_player *player);

char		*sgt(char *msg, t_game *game);
char		*seg(char *msg, int win_team);
char		*smg(char *msg, char *serv_msg);
char		*suc(char *msg);
char		*sbp(char *msg);

/*grp_action*/
char		*grp_do_incant(t_player *player);
char		*grp_incant_done(t_player *player, int res);
char		*grp_expulse(t_player *player);
char		*grp_broad(t_player *player, char *broad);

/*grp_connex*/
char		*grp_connex_monit(t_game *game);
char		*grp_connex_player(t_game *game, t_player *player);
char		*grp_connex_zombie(t_game *game, t_player *player, 
				   t_eggs *egg);


/*grp_egg*/
char		*grp_fork(t_player *player);
char		*grp_fork_end(t_player *player, t_eggs *egg);
char		*grp_egg_hatch(t_eggs *egg);
char		*grp_egg_die(t_eggs *egg);

/*grp_ending*/
char		*grp_player_die(t_player *player);
char		*grp_party_end(int winner);

/*grp_move*/
char		*grp_move(t_player *player);

/*grp_object*/
char		*grp_get_object(t_player *player, int obj);
char		*grp_drop_object(t_player *player, int obj);

#endif		/*__COMMUNICATION_H__*/
