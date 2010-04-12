/*
** t_packet for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Apr 11 14:39:48 2010 francois1 ancel
** Last update Mon Apr 12 16:16:52 2010 Florian Chanioux
*/

#ifndef			T_PACKET_INCLUDED
# define		T_PACKET_INCLUDED

typedef struct
{
  int			id_player;
  char			*mess;
}			t_rep;

typedef struct
{
  int			player_id;
  int			ac;
  char			*av[2];
  struct timeval	time;
  int			duration;
  t_rep			*response; /* tableau */
}			t_packet;

typedef struct
{
  char			*inst;
  void			(*ptr_func)();
  int			delay;
}			t_inst;

#endif			/* !T_PACKET_INCLUDED */
