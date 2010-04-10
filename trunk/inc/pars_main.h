/*
**
*/

#ifndef			H_PARS_MAIN_INCLUDED
# define		H_PARS_MAIN_INCLUDED

#include		"t_struct.h"

void			puterr(char *str, int quit);
t_opt			*parser(int ac, char **av);
void			fill_server(t_opt *opt, t_server *server);
void			check(int ac, char **av, t_server *server);

#endif			/*H_PARS_MAIN_INCLUDED*/
