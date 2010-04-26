/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 13:10:03 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef __APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/freeglut_std.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif


#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		tempo(t_game *game)
{
  while (game->map.h == -42)
    {
       search_msg(game);
       if (SDL_PollEvent(&(game->event)))
	{
	  if (game->event.type == SDL_QUIT)
	    {
	      exit_func(game);
	      exit(EXIT_SUCCESS);
	    }
	}
       if (game->map.h == -42)
	 write(game->serv.socket, "msz\n", 4);
    }
}

void		test_create_player(t_game *game, int id, int team)
{
  t_player	*pl;
  t_player	*new;
  static long	seed;
  int		i;

  srandom(seed + time(NULL));
  seed = random();
  pl = game->player;
  if (pl != NULL)
    while (pl->next_pg != NULL)
      pl = pl->next_pg;
  new = xmalloc(sizeof(t_player));
  if (pl)
    pl->next_pg = new;
  else
    game->player = new;
  new->next_pg = NULL;
  new->id = id;
  new->lv = random() % 8;
  new->sens = random() % 4;
  new->pos.x = random() % 10;
  new->pos.y = random() % 10;
  i = -1;
  while (++i != 8)
    new->inventaire[i] = random() % 10;
  i = -1;
  while (++i != 5)
    {
      if (team == 1)
	new->team = 1;
      else
	new->team = 2;
    }
}

void		test_init_player(t_game *game)
{
  int		x;
  int		y;
  int		o;

  test_create_player(game, 1234, 1);
  test_create_player(game, 34, 1);
  test_create_player(game, 3234, 1);
  test_create_player(game, 1534, 1);

  test_create_player(game, 9871, 2);
  test_create_player(game, 3487, 2);
  test_create_player(game, 6481, 2);
  test_create_player(game, 1598, 2);

  x = -1;
  while (++x != 5)
    {
      y = -1;
      while (++y != 5)
	{
	  o = -1;
	  while (++o != 8)
	    game->map.t_case[x][y].obj[o][2] = 2;
	}
    }
}

int		main(int ac, char *av[])
{
  t_game	game;

  av = av;
  if (ac > 2)
    {
      connect_to_serv(&game, av);
      glutInit(&ac, av);
      init_video(&game);
      init_game(&game);
      game.map.h = -42;
      game.serv.cbuf = cbuf_new();
      tempo(&game);
      /* test_init_player(&game); */
      printAttributes();
      init_texture(&game);
      init_3dsmodel(&game);
      initGL(&game);
      mainloop(&game);
      puts("end of program");
      SDL_Quit();
    }
  else
    printf("Usage : ./zappy addr port\n");
  return (EXIT_SUCCESS);
}
