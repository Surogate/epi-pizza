/*
** time_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Apr 18 14:00:07 2010 francois1 ancel
** Last update Sun Apr 18 14:00:07 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int	time_cmp(struct timeval *one, struct timeval *two)
{
  int	diff;

  diff = one->tv_sec - two->tv_sec;
  if (diff)
    return (diff);
  diff = one->tv_usec - two->tv_usec;
  return (diff);
}

int	timeminus(struct timeval *to, struct timeval *one, struct timeval *two)
{
  int	sec;
  int	usec;

  sec = one->tv_sec - two->tv_sec;
  if (sec < 0)
    return (EXIT_FAILURE);
  usec = one->tv_usec - two->tv_usec;
  if (usec < 0)
    {
      usec = 1000000 + usec;
      --sec;
    }
  to->tv_sec = sec;
  to->tv_usec = usec;
  return (EXIT_SUCCESS);
}

void	timeend(struct timeval *end, struct timeval *start,
		struct timeval *delay, int nbr)
{
  int	usec;

  end->tv_sec = start->tv_sec + (nbr * delay->tv_sec);
  usec = start->tv_usec + (nbr * delay->tv_usec);
  end->tv_sec += usec / 1000000;
  end->tv_usec = usec % 1000000;
}

void	gen_delay(struct timeval *delay, int nbr)
{
  int	usec;

  if (nbr == 0)
    {
      delay->tv_sec = 0;
      delay->tv_usec = 0;
      return ;
    }
  usec = 1000000 / nbr;
  delay->tv_sec = usec / 1000000;
  delay->tv_usec = usec % 1000000;
}
