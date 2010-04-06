/*
** t_struct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:24 2010 francois1 ancel
** Last update Tue Apr  6 18:19:44 2010 Florian Chanioux
*/

#ifndef T_STRUCT_INCLUDED
# define T_STRUCT_INCLUDED

typedef struct
{
  int		team;
  int		level;
  t_ressource	*invent;
  int		dir;
  t_map		*pos;
  /* mettre les info lier au joueurs */
}		t_player;

typedef struct
{
  int		ress[RESS_NUM];
  t_list	*player;
}		t_case;

typedef struct	s_map
{
  struct s_map	*n;
  struct s_map	*no;
  struct s_map	*o;
  struct s_map	*so;
  struct s_map	*s;
  struct s_map	*se;
  struct s_map	*e;
  struct s_map	*ne;
  t_case	*cas;
}		t_map;

typedef struct
{
  int		port;
  int		height;
  int		width;
  char		*teamname;
  int		nb_client;
  int		delay;
}

typedef struct
{
  t_map		**map;
  t_list	*player;
  t_list	*eggs;
}		t_game;

typedef struct
{
  int		ac;
  char		**av;
}		t_packet;

typedef struct
{
  int		sock;
  int		type;
  t_cbuf	cbuf;
  t_list	*t_packet;
}		t_client;

typedef	struct
{
  int		nb_player;
  int		ress_need[RESS_NUM];
}		t_incant;

#endif
