/*
** concatene_msg_view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
**
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
**
** Started on  Wed Apr 14 13:18:55 2010 pierre1 boutbel
** Last update Sat Apr 24 05:50:01 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_game_stc.h"
#include	"xfunc.h"

static char		msg_ress[RESS_NUM][12] = 
  {
    "nourriture", 
    "linemate", 
    "deraumere", 
    "sibur", 
    "mendiane", 
    "phiras", 
    "thystame"
  };

char		*add_player(t_vision *cur_case, char *msg)
{
  t_list	*cur_player;
  int		flag;
  int		i;

  i = -1;
  flag = 0;
  while (++i != RESS_NUM)
    if (cur_case->cas->cas.ress[i] != 0)
      flag = 1;
  cur_player = cur_case->cas->cas.player;
  while (cur_player->data != NULL)
    {
      msg = xrealloc(msg, xstrlen(msg) + xstrlen(MSG_JOUEUR) + 3);
      if (flag == 1)
	snprintf(msg + strlen(msg), xstrlen(MSG_JOUEUR) + 3, "%s ", MSG_JOUEUR);
      else
	snprintf(msg + strlen(msg), xstrlen(MSG_JOUEUR) + 3, "%s", MSG_JOUEUR);
      cur_player = cur_player->next;
    }
  return (msg);
}

static int	find_last_ress(t_case cas)
{
  int		i;

  i = RESS_NUM - 1;
  while ((cas.ress[i] == 0) && (i != -1))
    i--;
  if ((cas.ress[RESS_NUM - 1] != 0) || (i == -1))
    return (RESS_NUM - 1);
  else
    return (i);
}

char		*add_ressource(t_vision *cur_case, char *msg)
{
  int		num_ress;
  int		nb_ress;
  int		count;

  count = 0;
  num_ress = -1;
  while (++num_ress != RESS_NUM)
    count = count + cur_case->cas->cas.ress[num_ress];
  msg = xrealloc(msg, xstrlen(msg) + (15 * count));
  num_ress = -1;
  while (++num_ress != RESS_NUM)
    {
      nb_ress = cur_case->cas->cas.ress[num_ress] + 1;
      while (--nb_ress >= 2)
	  snprintf(msg + xstrlen(msg), 12, "%s ", msg_ress[num_ress]);
      if (nb_ress != 0)
	{
	  if (num_ress == find_last_ress(cur_case->cas->cas))
	    snprintf(msg + xstrlen(msg), 14, "%s", msg_ress[num_ress]);
	  else
	    snprintf(msg + xstrlen(msg), 14, "%s ", msg_ress[num_ress]);
	}
    }
  return (msg);
}

char		*explore_case(t_vision *cur_case, char *msg)
{
  int		i;

  if (cur_case->cas->cas.player != NULL)
    msg = add_player(cur_case, msg);
  msg = add_ressource(cur_case, msg);
  msg = xrealloc(msg, xstrlen(msg) + 4);
  if (cur_case->next == NULL)
    msg = strncat(msg, ",", 1);
  if (cur_case->next != NULL)
    {
      i = -1;
      while (++i != RESS_NUM)
	if (cur_case->next->cas->cas.ress[i] != 0)
	  break;
      if (i == RESS_NUM)
	strncat(msg, ",", 1);
      else
	{
	  msg = xrealloc(msg, xstrlen(msg) + 3);
	  strncat(msg, ", ", 2);
	}
    }
  return (msg);
}

char		*concatene_msg(t_vision *list)
{
  char		*msg;
  t_vision	*cur;
  int		len;

  cur = list;
  msg = xmalloc(2 * sizeof(*msg));
  msg[0] = '{';
  msg[1] = '\0';
  while (cur != NULL)
    {
      msg = explore_case(cur, msg);
      cur = cur->next;
    }
  len = xstrlen(msg);
  msg = xrealloc(msg, len + 3);
  msg[len - 1] = '}';
  msg[len] = '\n';
  msg[len + 1] = '\0';
  return (msg);
}
