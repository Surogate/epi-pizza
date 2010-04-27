/*
** instruction.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 13 11:03:54 2010 francois1 ancel
** Last update Sun Apr 18 12:31:50 2010 pierre1 boutbel
*/

#ifndef INSTRUCTION_C_INCLUDED
# define INSTRUCTION_C_INCLUDED

int		find_elem(t_packet *ref, t_player *test);
void		treatment_intr(t_game *game, t_packet *packet);
int		treatment_duration(t_packet *packet);
int		authent(t_game *game, t_packet *packet);

#endif
