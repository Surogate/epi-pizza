/*
** server_ending.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Fri Apr 16 16:39:00 2010 pierre1 boutbel
** Last update Tue Apr 20 17:01:34 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<stdlib.h>

#include	"define.h"
#include	"my_list.h"
#include	"t_struct.h"
#include	"xfunc.h"

static int	count_team(t_team *begin)
{
  t_team	*next;
  int		count;
  
  count = 0;
  next = begin;
  while (next != NULL)
    {
      count++;
      next = next->next;
    }
  return (count);
}

void		is_ending(t_game *game)
{
  int		*people_team;
  int		nb_teams;
  t_player	*cur_pl;
  t_list	*list;
  int		i;

  nb_teams = count_team(game->server.teamname);
  people_team = xmalloc((nb_teams + 2) * sizeof(int));
  i = -1;
  while (++i != nb_teams + 1)
    people_team[i] = 0;
  list = game->player;
  while (list->data != NULL)
    {
      cur_pl = (t_player *)list->data;
      if (cur_pl->level == MAX_LEVEL)
	people_team[cur_pl->team]++;
      list = list->next;
    }
  i = -1;
  while (++i != nb_teams + 1)
    if (people_team[i] == NB_WIN)
      game->state = i;
}
