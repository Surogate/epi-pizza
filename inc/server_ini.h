/*
** server_ini.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 12 13:46:51 2010 francois1 ancel
** Last update Mon Apr 12 13:46:51 2010 francois1 ancel
*/

#ifndef SERVER_INI_C_INCLUDED
# define SERVER_INI_C_INCLUDED

int			init_svr(int sock, t_server *svr, t_select *slt_par);
int			init_svr_par(t_select *slt_par, 
				     t_vector *client, int svr_sock);

#endif
