/*
** view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:20:07 2010 pierre1 boutbel
** Last update Wed Apr 14 13:20:09 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<stdlib.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_packet.h"
#include	"t_game_stc.h"
#include	"xfunc.h"

char		*concatene_msg(t_vision *list);

static t_dir_v	gl_dir[5] = {
  {DIR_N, M_NO, M_E},
  {DIR_E, M_NE, M_S},
  {DIR_S, M_SE, M_O},
  {DIR_O, M_SO, M_N},
  {0, 0, 0}
};

static t_map	*find_left(t_vision *list, t_dir_v *dir, int level)
{
  t_vision	*cur;

  cur = list;
  while (cur != NULL)
    {
      if (cur->level == level)
	return (cur->cas->card[dir->up_left]);
      cur = cur->next;
    }
  return (NULL);
}

static t_vision *add_case(t_vision *list, t_map *map, int level)
{
  t_vision	*new;
  t_vision	*cur;
  t_vision	*old;

  new = xmalloc(sizeof(t_vision));
  cur = list;
  old = cur;
  while (cur != NULL)
    {
      old = cur;
      cur = cur->next;
    }
  old->next = new;
  new->next = NULL;
  new->cas = map;
  new->level = level + 1;
  new->num = old->num + 1;
  return (list);
}

static t_vision	*add_level(t_vision *s_vision, t_dir_v *dir, int level)
{
  t_map		*left;
  int		count;
  int		i;

  i = 0;
  count = 0;
  left = find_left(s_vision, dir, level);
  while (i != level * 2)
    {
      s_vision = add_case(s_vision, left, level);
      left = left->card[dir->right];
      i++;
    }
  return (s_vision);
}

static void	free_list_vision(t_vision *s_vision)
{
  t_vision	*next;

  next = s_vision;
  while (next != NULL)
    {
      s_vision = next;
      next = s_vision->next;
      free(s_vision);
    }
}

void		try_view(t_packet *packet, t_player *player)
{
  t_vision	*s_vision;
  int		i;

  i = 0;
  s_vision = xmalloc(sizeof(s_vision));
  s_vision->next = NULL;
  s_vision->level = 0;
  s_vision->num = 0;
  s_vision->cas = player->pos;
  while (player->level < i)
    {
      s_vision = add_level(s_vision, &gl_dir[player->dir - 1], i);
      i++;
    }
  packet->response = xmalloc(sizeof(t_rep)); 
  packet->response->mess = concatene_msg(s_vision);
  packet->response->id_player = packet->player_id;
  packet->ac_rep = 1;
  free_list_vision(s_vision);
}
