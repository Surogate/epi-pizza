/*
** t_svr_stc for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr  9 12:53:57 2010 francois1 ancel
** Last update Fri Apr  9 13:59:47 2010 Florian Chanioux
*/

#ifndef			T_SVR_STC_INCLUDED
# define		T_SVR_STC_INCLUDED

# ifndef		T_SERVER_INCLUDED
#  define		T_SERVER_INCLUDED

typedef struct		s_team
{
  char			*team;
  int			lim;
  struct s_team		*next;
}			t_team;

typedef struct
{
  int			port;
  int			height;
  int			width;
  t_team		*teamname;
  int			nb_client;
  int			delay;
}			t_server;

# endif			/* !T_SERVER_INCLUDED */

typedef struct
{
  int			sock;
  int			team;
  t_cbuf		cbuf;
  int			auth;
  t_packet		packet[10];
  int			used;
  int			cons;
}			t_client;

typedef struct
{
  int			fd_max;
  fd_set		fd_read;
  struct timeval	timeout;
  struct timeval	*time;
}			t_select;

typedef struct
{
  t_vector		*client;
  t_vector		*action;
}			t_svr_vector;

#endif			/* !T_SVR_STC_INCLUDED */
