/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 14 15:35:03 2010 Florian Chanioux
*/
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	"../includes/define.h"
#include	"../includes/struct.h"
#include	"../includes/proto.h"

int		main(void)
{
  t_game	game;
  int		i;

  init_game(&game);
  initAttributes();
  /* createSurface(0); Create GL context */
  printAttributes();
  initGL();
  mainloop(&game);
  SDL_Quit();

  /*
  while (1)
  {
    if (SDL_PollEvent(&game.event))
    {
      i = 0;
      while (event_type[i].type)
      {
	if (game.event.type == event_type[i].type)
	  event_type[i].func(&game);
	i++;
      }
    }
    SDL_FillRect(game.screen, NULL,
		 SDL_MapRGB(game.screen->format, 0, 0, 0));
    display_map(&game);
    display_mouse(&game);
    if (SDL_Flip(game.screen) == -1)
    {
      printf("Refresh fail\n");
      exit(EXIT_FAILURE);
    }
  }
  */
  return (EXIT_SUCCESS);
}
