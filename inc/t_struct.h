/*
** t_struct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:24 2010 francois1 ancel
** Last update Thu Apr 15 17:48:45 2010 Florian Chanioux
*/

#ifndef		T_STRUCT_INCLUDED
# define	T_STRUCT_INCLUDED

typedef struct
{
  int		ress[RESS_NUM];
  t_list	*player;
}		t_case;

typedef	struct
{
  int		nb_player;
  int		ress_need[RESS_NUM];
}		t_incant;

typedef struct
{
  int		x;
  int		y;
}		t_card;

typedef struct	s_map
{
  struct s_map	*card[M_CARD];
  int		cout;
  t_case	cas;
}		t_map;

typedef struct
{
  int		player_id;
  int		team;
  int		level;
  int		dir;
  t_map		*pos;
  int		ress[RESS_NUM];
}		t_player;

typedef struct		s_team
{
  char			*team;
  int			lim;
  struct s_team		*next;
}			t_team;

typedef struct		s_opt
{
  char			*option;
  int			value;
  t_team		*team;
}			t_opt;

# ifndef	T_SERVER_INCLUDED
#  define	T_SERVER_INCLUDED

typedef struct
{
  int		port;
  int		height;
  int		width;
  t_team	*teamname;
  int		nb_client;
  int		delay;
}		t_server;

# endif		/* !T_SERVER_INCLUDED */

typedef struct
{
  t_map		*pos;
  int		team;
  int		id;
}		t_eggs;

typedef struct
{
  t_server	server;
  struct s_map 	**map;
  t_list	*player;
  t_list	*eggs;
}		t_game;

#endif		/* !T_STRUCT_INCLUDED */
