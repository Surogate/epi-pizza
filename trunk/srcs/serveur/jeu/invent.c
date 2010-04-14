/*
** invent.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:19:43 2010 pierre1 boutbel
** Last update Wed Apr 14 13:19:44 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<string.h>
#include	<stdlib.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_game_stc.h"
#include	"t_packet.h"
#include	"xfunc.h"

void		try_drop_obj(t_packet *packet, t_player *player)
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
      if (num_ress >= RESS_NUM || player->ress[num_ress] == 0)
	  packet->response->mess = KO;
      else
	{
	  player->ress[num_ress]--;
	  player->pos->cas.ress[num_ress]++;
	  packet->response->mess = OK;
	}
    }
  else
    packet->response->mess = KO;
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
	packet->response->mess = KO;
      else
	{
	  packet->response->mess = OK;
	  player->ress[num_ress]++;
	  player->pos->cas.ress[num_ress]--;
	}
    }
  else
    packet->response->mess = KO;
  packet->ac_rep = 1;
}

static int	my_dec_pow(int nb)
{
  int		resu;
  int		i;

  i = 1;
  resu = 10;
  while (i != nb)
    {
      resu = resu * 10;
      i++;
    }
  return (resu);
}

static char	*int_to_str(int nbr)
{
  char		*str;
  int		len;

  if (nbr == 0)
    {
      str = xmalloc(2 * sizeof(char));      
      str[0] = '0';
      str[1] = '\0';
      return (str);
    }
  len = 12;
  str = xmalloc(12 * sizeof(char));
  while (--len)
    str[11 - len] = ((nbr % my_dec_pow(len + 1)) / my_dec_pow(len)) + '0';
  str[11] = (nbr % my_dec_pow(len + 1)) + '0';
  str[12] = '\0';
  len = 0;
  while (str[0] == '0')
    str++;
  return (str);
}

void		try_invent(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
  int		num_ress;
  char		*nb_ress;
  char		*msg;

  num_ress = 0;
  msg = xmalloc(sizeof(char) * 2);
  msg[0] = '{';
  msg[1] = '\0';
  while (num_ress != RESS_NUM)
    {
      nb_ress = int_to_str(player->ress[num_ress]);
      msg = xrealloc(msg, strlen(msg) + strlen(msg_ress[num_ress]) + 
		     strlen(nb_ress) + 3);
      msg = strcat(msg, msg_ress[num_ress]);
      msg = strcat(msg, " ");
      msg = strcat(msg, nb_ress);
      if (++num_ress != RESS_NUM)
	msg = strcat(msg, ", ");
      /*free(nb_ress);*/
    }
  msg = strcat(msg, "}");
  packet->response = xmalloc(sizeof(t_rep));
  packet->response->mess = msg;
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
}
