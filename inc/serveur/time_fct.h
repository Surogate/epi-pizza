/*
** time_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Apr 18 14:51:10 2010 francois1 ancel
** Last update Sun Apr 18 14:51:10 2010 francois1 ancel
*/

#ifndef TIME_FCT_INCLUDED
# define TIME_FCT_INCLUDED

int	time_cmp(struct timeval *one, struct timeval *two);
int	timeminus(struct timeval *to, struct timeval *one, struct timeval *two);
void	timeend(struct timeval *end, struct timeval *delay, int nbr);
void	gen_delay(struct timeval *delay, int nbr);

#endif
