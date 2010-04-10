/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/

#ifndef		PROTO_H
# define	PROTO_H

/*event func*/
void		mouse_move(t_game *game);
void		mouse_up(t_game *game);
void		mouse_down(t_game *game);

/*xSDL*/
void		xSDL_Flip(SDL_Surface *screen);
int		xSDL_Init(Uint32 flags);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

#endif
