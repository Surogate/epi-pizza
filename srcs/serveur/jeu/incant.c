/*
Header
*/

#include	<stdio.h>

#include	"../../../inc/t_struct.h"
#include	"../../../inc/my_list.h"
#include	"../../../inc/define.h"

static t_incant	gl_incant[INCANT_NUM]{
  {1, {1, 0, 0, 0, 0, 0}};
  {2, {1, 1, 1, 0, 0, 0}};
  {2, {2, 0, 1, 0, 2, 0}};
  {4, {1, 1, 2, 0, 1, 0}};
  {4, {1, 2, 1, 3, 0, 0}};
  {6, {1, 2, 3, 0, 1, 0}};
  {6, {2, 2, 2, 2, 2, 1}};
  {0, NULL};
}

int		try_incant(t_player *player)
{
  int		i;

  if (player->level => 8 || gl_incant[player->level - 1].nb_player > 
      my_l_size((t_list*)player))
    return (EXIT_FAILURE);
  i = 0;
  while (i != RESS_NUM) 
    {
      if (ress_need[i] > player->ress[i])
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
