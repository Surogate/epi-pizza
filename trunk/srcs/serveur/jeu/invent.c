/*
** invent.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:43 2010 pierre1 boutbel
** Last update Sat Apr 24 05:49:08 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_game_stc.h"
#include	"serveur/t_packet.h"
#include	"xfunc.h"

void		try_drop_obj(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
  char		*name_res;
  int		num_ress;

  num_ress = 0;
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(LEN_OK * sizeof(char));
  packet->response->id_player = packet->player_id;
  if (packet->ac == 2)
    {
      name_res = packet->av[1];
      while (num_ress != RESS_NUM && strcmp(name_res, msg_ress[num_ress]) != 0)
	num_ress++;
      if (num_ress >= RESS_NUM || player->ress[num_ress] == 0)
	snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
      else
	{
	  player->ress[num_ress]--;
	  player->pos->cas.ress[num_ress]++;
	  snprintf(packet->response->mess, LEN_OK, "%s\n", OK);
	}
    }
  else
    snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
  packet->ac_rep = 1;
}

void		try_take_obj(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
  char		*name_res;
  int		num_ress;

  num_ress = 0;
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = xmalloc(3 * sizeof(char));
  packet->response->id_player = packet->player_id;
  if (packet->ac == 2)
    {
      name_res = packet->av[1];
      while (num_ress != RESS_NUM && strcmp(name_res, msg_ress[num_ress]) != 0)
	num_ress++;
      if (num_ress == RESS_NUM || player->pos->cas.ress[num_ress] == 0)
	snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
      else
	{
	  snprintf(packet->response->mess, LEN_OK, "%s\n", OK);
	  player->ress[num_ress]++;
	  player->pos->cas.ress[num_ress]--;
	}
    }
  else
    snprintf(packet->response->mess, LEN_OK, "%s\n", KO);
  packet->ac_rep = 1;
}

void		try_invent(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
  int		num_ress;
  char		*msg;

  num_ress = -1;
  msg = xmalloc(sizeof(char));
  msg[0] = '\0'; 
  while (++num_ress != RESS_NUM)
    {
      msg = xrealloc(msg, strlen(msg) + strlen(msg_ress[num_ress]) + 13);
      if (num_ress == 0)
	sprintf(msg, "{%i,", player->ress[num_ress]);
      else if (num_ress != RESS_NUM)
	sprintf(msg, "%s %i,", msg, player->ress[num_ress]);
      else
	sprintf(msg, "%s %i", msg, player->ress[num_ress]);
    }
  msg = strcat(msg, "}\n");
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = msg;
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
}
