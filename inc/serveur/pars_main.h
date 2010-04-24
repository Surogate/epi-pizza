/*
** define for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:18:10 2010 francois1 ancel
** Last update Fri Apr  9 16:36:54 2010 Florian Chanioux
*/

#ifndef			H_PARS_MAIN_INCLUDED
# define		H_PARS_MAIN_INCLUDED

#include		"t_struct.h"

void			puterr(char *str, int quit);
t_opt			*parser(int ac, char **av);
void			fill_server(t_opt *opt, t_server *server);
void			check(int ac, char **av, t_server *server);

#endif			/*H_PARS_MAIN_INCLUDED*/
