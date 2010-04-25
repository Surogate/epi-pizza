/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 10:20:04 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glut.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		create_map(t_game *game)
{
  int		y;
  int		x;
  int		temp;

  game->map.t_case= malloc(game->map.h * sizeof(*(game->map.t_case)));
  y = -1;
  while (++y < game->map.h)
  {
    game->map.t_case[y] = malloc(game->map.w * sizeof(t_case));
    x = -1;
    while (++x < game->map.w)
    {
      game->map.t_case[y][x].player = 0;
      temp = -1;
      while (++temp < 7)
        game->map.t_case[y][x].obj[temp] = 0;
    }
  }
}

void		init_game(t_game *game)
{
  game->screen = load_window();
  game->mouse.clicked = 0;
  game->team = NULL;
  game->map.rot = 0;
  game->map.z = 200;
  game->info.crazy = 1;
  game->info.pos.x = 0;
  game->info.pos.y = 0;
  game->player = 0;
  SDL_ShowCursor(1);
}
