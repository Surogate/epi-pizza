/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 13:26:36 2010 Florian Chanioux
*/

#ifndef		STRUCT_H
# define	STRUCT_H

typedef struct	s_event
{
  Uint8		type;
  int		(*func)();
}		t_event;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_mouse
{
  int		clicked;
  SDL_Surface	*img[2];
  t_pos		move;
}		t_mouse;

typedef struct	s_info
{
  t_pos		pos;
  int		dir;
  int		size_h;
  int		size_w;
}		t_info;

typedef struct	s_play
{
  int		lv;
  t_pos		pos;
  int		id;
  struct s_play	*next;
}		t_player;

typedef struct	s_case
{
  int		obj[7];
  t_player	*player;
}		t_case;

typedef struct	s_map
{
  t_case	**t_case;
  SDL_Surface	*fond;
}		t_map;

typedef struct	s_texture
{
  GLuint	floor;
  GLuint	side;
}		t_texture;

typedef struct	s_model
{
  obj_type	*trantorien;
  obj_type	*ressource;
  obj_type	*eggs;
}		t_model;

typedef struct	s_video
{
  int		text;
  int		light;
  int		fog;
  int		aliasing;
  int		cam[3];
}		t_video;

typedef struct	s_circ
{
  char		buff[BUFSIZE];
  int		cur;
  int		num;
  struct s_circ	*next;
}		t_circle;

typedef struct	s_serv
{
  int		socket;
  fd_set	fd_read;
  fd_set	fd_write;
  int		beg[2];
  t_circle	circ;
  t_circle	*current;
}		t_serv;

typedef struct	s_game
{
  SDL_Event	event;
  SDL_Surface	*screen;
  t_video	video;
  t_model	model;
  t_texture	texture;
  t_info	info;
  t_mouse	mouse;
  t_map		map;
  Uint32	ticks;
  TTF_Font	*font;
  t_serv	serv;
}		t_game;

#endif		/*STRUCT_H*/
