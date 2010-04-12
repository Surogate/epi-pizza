/*
Header
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/t_packet.h"
#include	"../../../inc/xfunc.h"

static t_incant	gl_incant[INCANT_NUM + 1] = {
  {1, {0, 1, 0, 0, 0, 0, 0}},
  {2, {0, 1, 1, 1, 0, 0, 0}},
  {2, {0, 2, 0, 1, 0, 2, 0}},
  {4, {0, 1, 1, 2, 0, 1, 0}},
  {4, {0, 1, 2, 1, 3, 0, 0}},
  {6, {0, 1, 2, 3, 0, 1, 0}},
  {6, {0, 2, 2, 2, 2, 2, 1}},
  {0, {0, 0, 0, 0, 0, 0, 0}}
};

static int	check_incant(t_player *player)
{
  int		i;
  int		len;

  printf("Nombre de joueurs attendus : %i\n", 
	 gl_incant[player->level - 1].nb_player);
  len = my_l_size(player->pos->cas.player);
  printf("Nombre de joueurs actuellement : %i\n", len);

  if (player->level <= 8)
    if (gl_incant[player->level - 1].nb_player != len)
      {
	puts("Il n'y a pas le bon nombre de personnes sur la case");
	return (EXIT_FAILURE);
      }
  i = 1;
  while (i != RESS_NUM)
    {
      if (gl_incant[player->level - 1].ress_need[i] != player->pos->cas.ress[i])
	{
	  printf("Il manque la ressource tab[%i]. On attend : %i, on a : %i",
		 i, gl_incant[player->level - 1].ress_need[i], 
		 player->pos->cas.ress[i]);
	  
	  return (EXIT_FAILURE);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

void		try_incant(t_packet *packet, t_player *player)
{
  /*  char		msg[LEN_ELEV];*/
  int		res;
  int		i;

  res = check_incant(player);
  if (res == EXIT_SUCCESS)
    {
      puts("L'incantation est un succes");

      packet->response = xmalloc((my_l_size(player->pos->cas.player) + 2) *
			   sizeof(packet->response));
      i = 1;
      packet->response[0].mess = ELEV_OK;
      packet->response[0].id_player = player->player_id;

      printf("Reponse pour le premier joueur %i : %s\n",
	   packet->response[0].id_player, packet->response[0].mess);

      /*
      while (cur_player != NULL)
	{
	  cur_player->level++
	  packet->response[i].id_player = cur_player->player_id;
	  msg[POS_ELEV_K] = cur_player->level;
	  packet->response[i].mess = msg;
	  printf("Reponse pour le premier joueur %i : %s\n",
		 packet->response[i].id_player, packet->response[i].mess);
	  i++;

	  list_pl = (t_list *)cur_player; 
	  (t_list *)cur_player = list_pl->next;
	}
      */

    }
  else
    packet->response->mess = KO;
}
