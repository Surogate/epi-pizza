/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 00:28:15 2010 Florian Chanioux
*/

#ifndef		__PROTO_H__
# define	__PROTO_H__

/* init */
void		init_game(t_game *game);
void		init_3dsmodel(t_game *game);
void		init_texture(t_game *game);
void		init_video(t_game *game);
void		initGL(t_game *game);
void		printAttributes();

/* load */
SDL_Surface	*load_window();
SDL_Surface	*img_load(char *path);
GLuint		loadtexture(const char * filename,int useMipMap);

/* game func interation keybord/mouse */
int		interaction(t_game *game);
int		exit_func();

/* keyboad */
int		key_func(t_game *game);

/*mouse func*/
int		mouse_move(t_game *game);
int		mouse_up(t_game *game);
int		mouse_down(t_game *game);

void		picking_mouse(t_game *game, int x, int y);

/* camera */
void		reshape();
void		camera();

/* Draw */
void		mainloop(t_game *game);


void		make_calllistes(t_game *game);
void		draw_gl(t_game *game, GLenum mode);
void		draw_map(t_game *game, GLenum mode);
void		draw_mob(t_game *game, GLenum mode);
void		draw_ressource(t_game *game, GLenum mode);
void		floor_with_t(t_game *game, int x, int y);
void		floor_without_t(int x, int y);
void		side_with_t(t_game *game, int x, int y);
void		side_without_t(int x, int y);

#endif
