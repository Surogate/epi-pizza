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
  t_case	cas;
}		t_map;

typedef struct
{
  int		team;
  int		level;
  int		dir;
  t_map		*pos;
  int		ress[RESS_NUM];
}		t_player;

# ifndef	T_SERVER_INCLUDED
#  define	T_SERVER_INCLUDED

typedef struct
{
  int		port;
  int		height;
  int		width;
  t_list	*teamname;
  int		nb_client;
  int		delay;
}		t_server;

# endif		/* !T_SERVER_INCLUDED */

# ifndef	T_PACKET_INCLUDED
#  define	T_PACKET_INCLUDED

typedef struct
{
  int		ac;
  char		**av;
}		t_packet;

typedef struct
{
  int		time;
  char		*response;
}		t_rep;

# endif		/* !T_PACKET_INCLUDED */

typedef	struct
{
  int		nb_player;
  int		ress_need[RESS_NUM];
}		t_incant;

typedef struct
{
  t_server	server;
  struct s_map 	**map;
  t_list	*player;
  t_list	*eggs;
}		t_game;

#endif		/* !T_STRUCT_INCLUDED */
