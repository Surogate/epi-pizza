/*
** server.h for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr  6 15:02:15 2010 Florian Chanioux
** Last update Sun Apr 18 12:31:28 2010 pierre1 boutbel
*/

#ifndef		_SERVEUR_H_
# define	_SERVEUR_H_


void		treatment_intr(t_game *game, t_packet *packet);
void		treatment_duration(t_packet *packet);

void		reset_pathfinding(t_game *game);
void		pathfinding(t_map *cas);



#endif		/* _SERVEUR_H_ */
