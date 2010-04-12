/*
** server.h for  in /home/Ayden/Epitech/Projet/Zappy/srcs/serveur
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr  6 15:02:15 2010 Florian Chanioux
** Last update Mon Apr 12 16:33:57 2010 Florian Chanioux
*/

#ifndef		_SERVEUR_H_
# define	_SERVEUR_H_


void		treatment_intr(t_game *game, t_packet *packet);
void		treatment_duration(t_game *game, t_packet *packet);


#endif		/* _SERVEUR_H_ */
