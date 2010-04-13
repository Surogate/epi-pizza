/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:10 2010 francois1 ancel
** Last update Fri Apr  9 16:36:54 2010 Florian Chanioux
*/

#ifndef			H_PARS_OPTION_INCLUDED
# define		H_PARS_OPTION_INCLUDED

#include		"t_struct.h"

void			init_opt(t_opt *opt, t_team *team);
void			modif_struc(t_opt *opt, int ac, char **av, int *i);
void			parse_option(t_opt *opt, int ac, char **av);

#endif			/*H_PARS_OPTION_INCLUDED*/
