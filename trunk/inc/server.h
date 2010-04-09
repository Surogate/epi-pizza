/*
** server.h for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr  6 15:02:15 2010 Florian Chanioux
** Last update Fri Apr  9 14:56:58 2010 Florian Chanioux
*/

#ifndef		_SERVEUR_H_
# define	_SERVEUR_H_

void		broadcast(t_packet *packet, t_player *player);
void		expulse(t_packet *packet, t_player *player);
void		incant(t_packet *packet, t_player *player);
void		multi(t_packet *packet, t_player *player);
void		connect(t_packet *packet, t_player *player);




#endif		/* _SERVEUR_H_ */
