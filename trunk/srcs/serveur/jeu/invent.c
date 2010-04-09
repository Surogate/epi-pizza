/*
  Header
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdlib.h>

#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/xfunc.h"

void		try_drop_obj(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][10] = {MSG_RESS};
  char		*name_res;
  int		num_ress;

  num_ress = 0;
  packet->response = NULL;
  if (packet->ac == 2)
    {
      name_res = packet->av[1];
      while (num_ress != RESS_NUM && strcmp(name_res, msg_ress[num_ress]) != 0)
	num_ress++;
      if (num_ress == RESS_NUM)
	packet->response = KO;
      if (player->ress[num_ress] == 0)
	packet->response = KO;
      player->ress[num_ress]--;
      player->pos->cas.ress[num_ress]++;
      if (packet->response == NULL)
	{
	  packet->response = OK;
	  packet->time = 7;
	}
    }
  else
    packet->response = KO;
}

void		try_take_obj(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][10] = {MSG_RESS};
  char		*name_res;
  int		num_ress;

  num_ress = 0;
  packet->response = NULL;
  if (packet->ac == 2)
    {
      name_res = packet->av[1];
      while (num_ress != RESS_NUM && strcmp(name_res, msg_ress[num_ress]) != 0)
	num_ress++;
      if (num_ress == RESS_NUM)
	packet->response = KO;
      if (player->pos->cas.ress[num_ress] == 0)
	packet->response = KO;
      player->ress[num_ress]++;
      player->pos->cas.ress[num_ress]--;
      if (packet->response == NULL)
	{
	  packet->response = OK;
	  packet->time = 7;
	}
    }
  else
    packet->response = KO;
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

  len = 11;
  str = xmalloc(11 * sizeof(char));
  while (len)
    {
      str[11 - len] = ((nbr % my_dec_pow(len + 1)) / my_dec_pow(len)) + '0';
      len--;
    }
  str[11] = '\0';
  len = 0;
  while (str[0] == '0')
    str++;
  return (str);
}

void		try_invent(t_packet *packet, t_player *player)
{
  char		msg_ress[RESS_NUM][10] = {MSG_RESS};
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
		    strlen(nb_ress) + 2);
      msg = strcat(msg, msg_ress[num_ress]);
      msg = strcat(msg, " ");
      msg = strcat(msg, nb_ress);
      num_ress++;
    }
  free(nb_ress);
  packet->response = msg;
  packet->time = 1;
}
