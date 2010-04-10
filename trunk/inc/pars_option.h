/*
**
*/

#ifndef			H_PARS_OPTION_INCLUDED
# define		H_PARS_OPTION_INCLUDED

#include		"t_struct.h"

void			init_opt(t_opt *opt, t_team *team);
void			modif_struc(t_opt *opt, int ac, char **av, int *i);
void			parse_option(t_opt *opt, int ac, char **av);

#endif			/*H_PARS_OPTION_INCLUDED*/
