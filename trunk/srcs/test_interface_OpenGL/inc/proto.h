/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 17 19:45:49 2010 Florian Chanioux
*/

#ifndef		PROTO_H
# define	PROTO_H

/*game func*/
void		init_game(t_game *game);
int		exit_func();

/*key func*/
int		key_func(t_game *game);

/*mouse func*/
int		mouse_move(t_game *game);
int		mouse_up(t_game *game);
int		mouse_down(t_game *game);

/*xSDL*/
void		xSDL_Flip(SDL_Surface *screen);
int		xSDL_Init(Uint32 flags);
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);

/* camera */
void		Reshape();
void		camera();


#endif
