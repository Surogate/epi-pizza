/*
** server_stt.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr  9 13:44:18 2010 francois1 ancel
** Last update Fri Apr  9 13:44:18 2010 francois1 ancel
*/

#ifndef SERVER_STT_C_INCLUDED
# define SERVER_STT_C_INCLUDED

int			init_svr(t_server *svr, t_select *slt_par);
int			select_loop(int svr_sock, t_select *slt_par);
int			svr_start(t_server *svr);

#endif
