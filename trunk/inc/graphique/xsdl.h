/*
** xsdl.h for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 20 23:16:15 2010 Florian Chanioux
** Last update Tue Apr 20 23:16:23 2010 Florian Chanioux
*/

#ifndef		_XSDL_H_
# define	_XSDL_H_

void		xSDL_Flip(SDL_Surface *screen);
int		xSDL_Init(Uint32 flags);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#endif		/* _XSDL_H_ */
