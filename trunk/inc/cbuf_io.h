/*
** cbuf_io.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 19 15:50:32 2010 francois1 ancel
** Last update Mon Mar 22 06:27:38 2010 lucas1 santamaria
*/

#ifndef		__CBUF_IO_C_INCLUDED__
# define	__CBUF_IO_C_INCLUDED__

char		*cbuf_read(t_cbuf *cbuf, int (*check_read)());
int		sock_read(int sock, char *to, int limit);
int		sock_write(int sock, char *from);
int		cbuf_write(t_cbuf *cbuf, int sock);

#endif		/*__CBUF_IO_C_INCLUDED__*/
