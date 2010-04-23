/*
** xsdl.h for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Apr 20 23:16:15 2010 Florian Chanioux
** Last update Wed Apr 21 22:50:50 2010 Florian Chanioux
*/

#ifndef		_XSDL_H_
# define	_XSDL_H_

void		xSDL_Flip(SDL_Surface *screen);
int		xSDL_Init(Uint32 flags);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

SDL_Surface	*xSDL_CreateRGBSurface(Uint32 flags, int width,
					      int height, int bitsperpixel,
					      Uint32 rmask, Uint32 gmask,
				       Uint32 bmask, Uint32 amask);

void		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect);



#endif		/* _XSDL_H_ */
