/*
** client_fct.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:18:53 2010 francois1 ancel
** Last update Sat Apr 10 15:18:53 2010 francois1 ancel
*/

#ifndef CLIENT_FCT_C_INCLUDED
# define CLIENT_FCT_C_INCLUDED

t_client		*new_client(int s);
int			add_client(t_vector *client, t_select *slt_par, 
				   int svr_sock);
#endif
