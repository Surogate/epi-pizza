/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/

#ifndef		STRUCT_H
# define	STRUCT_H

typedef struct	s_event
{
  Uint8		type;
  void		(*func)();
}		t_event;

typedef struct	s_msg
{
  char		*name;
  void		(*func)();
}		t_msg;

typedef struct	s_pos
{
  float		x;
  float		y;
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
  SDL_Surface	*ori;
}		t_map;

typedef struct	s_game
{
  SDL_Event	event;
  SDL_Surface	*screen;
  t_info	info;
  t_mouse	mouse;
  t_map		map;
  TTF_Font	*font;
}		t_game;

#endif		/*STRUCT_H*/
