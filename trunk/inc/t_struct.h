/*
** t_struct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:24 2010 francois1 ancel
** Last update Wed Apr  7 19:19:56 2010 Florian Chanioux
*/

#ifndef		T_STRUCT_INCLUDED
# define	T_STRUCT_INCLUDED

typedef struct
{
  int		ress[RESS_NUM];
  t_list	*player;
}		t_case;

typedef struct
{
  int		x;
  int		y;
}		t_card;

typedef struct	s_map
{
  struct s_map	*card[M_CARD];
  t_case	*cas;
}		t_map;

typedef struct
{
  int		team;
  int		level;
  int		dir;
  t_map		*pos;
  /* mettre les info lier au joueurs */
}		t_player;

typedef struct
{
  int		port;
  int		height;
  int		width;
  char		*teamname;
  int		nb_client;
  int		delay;
}		t_server;

typedef struct
{
  t_server	server;
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
  t_list	*t_packet;
}		t_client;

typedef	struct
{
  int		nb_player;
  int		ress_need[RESS_NUM];
}		t_incant;

#endif
