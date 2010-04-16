/*
** response.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 13 13:47:46 2010 francois1 ancel
** Last update Tue Apr 13 13:47:46 2010 francois1 ancel
*/

#ifndef RESPONSE_C_INCLUDED
# define RESPONSE_C_INCLUDED

int	auth_ok(t_packet *pak, int num_client, t_game *game);
int	auth_fail(t_packet *pak);

#endif
