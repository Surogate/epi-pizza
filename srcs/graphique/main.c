/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 15:16:57 2010 Florian Chanioux
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
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif


#include "graphique/3dsloader.h"
#include "graphique/define.h"
#include "graphique/struct.h"
#include "graphique/proto.h"

int		main(int ac, char *av[])
{
  t_game	game;

  if (ac > 2)
    {
      connect_to_serv(&game, av);
      init_video(&game);
      init_game(&game);
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
