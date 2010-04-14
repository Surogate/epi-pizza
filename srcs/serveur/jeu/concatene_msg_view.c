/*
** concatene_msg_view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:18:55 2010 pierre1 boutbel
** Last update Wed Apr 14 13:18:55 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>

#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"
#include	"../../../inc/t_struct.h"
#include	"../../../inc/t_game_stc.h"
#include	"../../../inc/xfunc.h"

char		*add_player(t_vision *cur_case, char *msg)
{
  t_list	*cur_player;
  int		flag;

  cur_player = cur_case->cas->cas.player;
  flag = 0;
  while (cur_player != NULL)
    {
      msg = xrealloc(msg, strlen(msg) + strlen(MSG_JOUEUR) + flag);
      msg = strcat(msg, MSG_JOUEUR);
      cur_player = cur_player->next;
      if (flag == 1 && cur_player != NULL)
	msg = strcat(msg, " ");
      if (flag == 0)
	flag++;
    }
  return (msg);
}

char		*add_ressource(t_vision *cur_case, char *msg)
{
  char		msg_ress[RESS_NUM][10] = {MSG_RESS};
  int		num_ress;
  int		nb_ress;
  int		flag;

  flag = 0;
  num_ress = 0;
  while (num_ress != RESS_NUM)
    {
      nb_ress = cur_case->cas->cas.ress[num_ress];
      while (nb_ress != 0)
	{
	  msg = xrealloc(msg, strlen(msg) + strlen(msg_ress[num_ress]) + flag);
	  msg = strcat(msg, msg_ress[num_ress]);
	  nb_ress--;
	  if (flag == 1 && nb_ress != 0)
	    msg = strcat(msg, " ");
	  if (flag == 0)
	    flag = 1;
	}
      num_ress++;
    }
  return (msg);
}

char		*explore_case(t_vision *cur_case, char *msg)
{  
  if (cur_case->cas->cas.player != NULL)
    msg = add_player(cur_case, msg);
  msg = add_ressource(cur_case, msg);
  msg = xrealloc(msg, strlen(msg) + 1);
  msg = strcat(msg, ",");
  return (msg);
}

char		*concatene_msg(t_vision *list)
{
  char		*msg;
  t_vision	*cur;

  cur = list;
  msg = xmalloc(2 * sizeof(char));
  msg[0] = '{';
  msg[1] = '\0';
  while (cur != NULL)
    {
      msg = explore_case(cur, msg);
      cur = cur->next;
    }
  msg = xrealloc(msg, strlen(msg) + 1);
  msg = strcat(msg, "}");
  return (msg);
}
