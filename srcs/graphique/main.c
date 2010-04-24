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
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/freeglut_std.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif


#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		tempo(t_game *game)
{
  while (game->map.h == -42)
    {
      /* printf("tour de boucle tempo\n"); */
      search_msg(game);
      if (SDL_PollEvent(&(game->event)))
	{
	  if (game->event.type == SDL_QUIT)
	    {
	      exit_func(game);
	      exit(EXIT_SUCCESS);
	    }
	}
    }
}

void		test_init_player(t_game *game)
{
  test_create_player();
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
      test_init_player(game);
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
