/*
** server_fct.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:19:01 2010 francois1 ancel
** Last update Sat Apr 10 15:19:01 2010 francois1 ancel
*/

#ifndef SERVER_FCT_C_INCLUDED
# define SERVER_FCT_C_INCLUDED

int		fetch_instr(t_vector *client, t_select *slt_par, t_game *game);
void		free_client(t_client *cli);

#endif
