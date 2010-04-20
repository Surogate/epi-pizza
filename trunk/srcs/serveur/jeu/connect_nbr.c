/*
** connect_nbr.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:56 2010 pierre1 boutbel
** Last update Tue Apr 20 18:25:07 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<stdio.h>
#include	<string.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

static int	count_member(t_game *game, int team)
{
  int		member;
  t_list	*list;
  t_player	*pl;

  member = 0;
  list = game->player;
  while (list->data != NULL)
    {
      pl = (t_player*)list->data;
      if (team == pl->team)
	member++;
      list = list->next;
    }
  return (member);
}

static int	count_present(t_game *game, int team)
{
  t_team	*list;
  int		count;

  count = 0;
  list = game->server.teamname; 
  while (list != NULL)
    {
      if (team == count)
	return (list->lim);
      count++;
      list = list->next;
    }
  return (0);
}

void		find_connect_nbr(t_packet *packet, t_player *player, 
				  t_game *game)
{
  int		member;
  int		lim;

  puts("***************TEST*******************");
  

  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(12 * sizeof(char));
  member = count_member(game, player->team);
  lim = count_present(game, player->team);

  printf("Lim : %i - mem %i\n", lim, member);

  if (lim - member >= 0)
    snprintf(packet->response->mess, 13, "%i\n", lim - member);
  else
    snprintf(packet->response->mess, 5, "%i\n", 0);
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;

  
  printf("Message pour %i : %s\n", packet->response->id_player, 
	 packet->response->mess);

  puts("***************TEST*******************");
}
