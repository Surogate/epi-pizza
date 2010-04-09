/*
** t_svr_stc for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr  9 12:53:57 2010 francois1 ancel
** Last update Fri Apr  9 13:59:47 2010 Florian Chanioux
*/

#ifndef		T_SVR_STC_INCLUDED
# define	T_SVR_STC_INCLUDED

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

typedef struct
{
  t_packet	pct_send;
  t_rep		*rep;
}		t_instruc;

typedef struct
{
  int		sock;
  int		type;
  t_list	*t_instruc;
}		t_client;

typedef struct
{
  int		fd_max;
  fd_set	fd_read;
  /* timeval de timeout */
}		t_select;


typedef struct
{
  t_packet	pct_send;
  t_rep		*rep;
}		t_instruc;



#endif		/* !T_SVR_STC_INCLUDED */
