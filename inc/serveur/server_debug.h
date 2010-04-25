/*
** server_debug.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 10:38:24 2010 francois1 ancel
** Last update Fri Apr 16 10:38:24 2010 francois1 ancel
*/

#ifndef SERVER_DEBUG_C_INCLUDED
# define SERVER_DEBUG_C_INCLUDED

void		debug_packet(t_packet *pak, char *str);
void		debug_client(t_client *cli, char *str);
void		debug_instr(t_packet *pak);

#endif
