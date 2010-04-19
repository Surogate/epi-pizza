/*
** concatene_msg_view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:18:55 2010 pierre1 boutbel
** Last update Mon Apr 19 16:57:52 2010 pierre1 boutbel
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

  cur_player = cur_case->cas->cas.player;
  while (cur_player->data != NULL)
    {
      msg = xrealloc(msg, strlen(msg) + strlen(MSG_JOUEUR));
      snprintf(msg, strlen(msg) + strlen(MSG_JOUEUR) + 3, "%s%s ", msg, 
	       MSG_JOUEUR);
      cur_player = cur_player->next;
    }
  return (msg);
}

static int	find_last_ress(t_case cas)
{
  int		i;
  
  i = RESS_NUM;
  while (cas.ress[i] != 0 && i != 0)
    i--;
  if (i == 0)
    return (RESS_NUM - 1);
  else 
    return (i - 1);
}

char		*add_ressource(t_vision *cur_case, char *msg)
{
  char		msg_ress[RESS_NUM][11] = {MSG_RESS};
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
	  if (nb_ress == 1 && num_ress == find_last_ress(cur_case->cas->cas))
	    {
	      printf("case : %i  => %s : %i %i\n", cur_case->num, msg_ress[num_ress], num_ress, nb_ress);
	      snprintf(msg, strlen(msg) + 14, "%s%s", msg, msg_ress[num_ress]);
	    }
	  else
	    snprintf(msg, strlen(msg) + 14, "%s%s ", msg, msg_ress[num_ress]);
	  nb_ress--;
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
  msg = xrealloc(msg, strlen(msg) + 2);
  msg = strcat(msg, ", ");
  return (msg);
}

char		*concatene_msg(t_vision *list)
{
  char		*msg;
  t_vision	*cur;
  int		len;

  cur = list;
  msg = xmalloc(2 * sizeof(char));
  msg[0] = '{';
  msg[1] = '\0';
  while (cur != NULL)
    {
      msg = explore_case(cur, msg);
      cur = cur->next;
    }
  msg = xrealloc(msg, strlen(msg) + 3);
  len = strlen(msg);
  msg[len - 1] = '}';
  msg[len] = '\n';
  msg[len + 1] = '\0';
  return (msg);
}
