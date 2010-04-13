/*
** instruction.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 13 11:03:54 2010 francois1 ancel
** Last update Tue Apr 13 11:03:54 2010 francois1 ancel
*/

#ifndef INSTRUCTION_C_INCLUDED
# define INSTRUCTION_C_INCLUDED

int		find_elem(void *ref, void *test);
void		treatment_intr(t_game *game, t_packet *packet);
int		treatment_duration(t_game *game, t_packet *packet);
int		authent(t_game *game, t_packet *packet);

#endif
