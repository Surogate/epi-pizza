/*
** t_struct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:24 2010 francois1 ancel
** Last update Mon Apr  5 18:18:24 2010 francois1 ancel
*/

#ifndef T_STRUCT_INCLUDED
# define T_STRUCT_INCLUDED

typedef struct
{
  int		team;
  int		level;
  /* mettre les info lier au joueurs */
}		t_player;

typedef struct
{
  /* liste doublement chainer de player */
  int		ress[RESS_NUM];
}		t_case;

typedef struct
{
  t_case	map[MAP_SIZ][MAP_SIZ];
  /* idealement il faudrais faire une liste doublement chainer
     des adresse des t_player sur la map */
}		t_game;

typedef struct
{
  int		ac;
  char		**av;
}		t_packet;

#endif
