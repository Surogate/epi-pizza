/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 05:19:12 2010 Florian Chanioux
*/

#ifndef		STRUCT_H
# define	STRUCT_H

typedef struct	s_event
{
  Uint8		type;
  int		(*func)();
}		t_event;

typedef struct
{
  int		r;
  int		g;
  int		b;
}		t_color;

typedef struct	s_serv
{
  int		socket;
  fd_set	fd_read;
  fd_set	fd_write;
  int		beg[2];
  t_cbuf	*cbuf;
}		t_serv;

typedef struct	s_msg
{
  char		*name;
  void		(*func)();
}		t_msg;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct	s_play
{
  int		id;
  GLuint	name;
  int		lv;
  int		sens;
  t_pos		pos;
  struct s_play	*next_pg;
  int		inventaire[7];
  int		team;
}		t_player;

typedef	struct	s_egg
{
  int		id;
  GLuint	name;
  t_pos		pos;
  int		team;
  struct s_egg	*next;
}		t_egg;

typedef struct	s_team
{
  int		id;
  char		name[50];
  struct s_team	*next;
}		t_team;

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
  int		time;
  int		crazy;
  int		size_h;
  int		size_w;
}		t_info;

typedef struct	s_case
{
  int		obj[7];
  t_player	*player;
}		t_case;

typedef struct	s_map
{
  t_case	**t_case;
  SDL_Surface	*fond;
  int		rot;
  int		z;
  int		h;
  int		w;
  int		select_p_o;
  int		select_c_o;
  int		select_p;
  int		select_c;
}		t_map;

typedef struct
{
  GLuint	floor;
  GLuint	floor_s;
  GLuint	side;
  GLuint	inter_u;
  GLuint	inter_d;
  GLuint	team;
  GLuint	select;
}		t_texture;

typedef struct
{
  obj_type	*trantorien[8];
  obj_type	*ressource[7];
  obj_type	*eggs;
}		t_model;

typedef struct
{
  int		text;
  int		light;
  int		fog;
  int		aliasing;
  int		cam[4];
}		t_video;

typedef struct	s_game
{
  SDL_Event	event;
  SDL_Surface	*screen;
  t_player	*player;
  t_team	*team;
  t_egg		*egg;
  t_video	video;
  t_model	model;
  t_texture	*texture;
  t_info	info;
  t_mouse	mouse;
  t_map		map;
  Uint32	ticks;
  t_serv	serv;
}		t_game;

#endif		/*STRUCT_H*/
