/*
** count_player.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/commun
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Thu Apr 15 16:49:21 2010 pierre1 boutbel
** Last update Sat Apr 24 05:59:10 2010 Florian Chanioux
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"serveur/define.h"
#include	"my_list.h"
#include	"serveur/t_struct.h"

int		count_player(t_game *game, int num_team)
{
  int		count;
  t_player	*pl;
  t_list	*list;

  count = 0;
  list = game->player;
  if (list == NULL)
    return (0);
  while (list != NULL)
    {
      pl = (t_player *)list->data;
      if (pl && pl->team == num_team)
	count++;
      list = list->next;
    }
  return (count);
}
