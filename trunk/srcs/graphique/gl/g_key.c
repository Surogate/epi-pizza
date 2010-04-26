/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr 26 10:12:35 2010 pierre1 boutbel
*/
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

int		key_escape(t_game *game)
{
  return (exit_func(game));
}

int		key_c(t_game *game)
{
  /*
    game->info.crazy++;
    game->info.crazy %= 2;
  */

  if (game->info.crazy == MOD_CRAZY)
    game->info.crazy = MOD_OK;
  else
    game->info.crazy = MOD_CRAZY;
  return (1);
}

int		key_b(t_game *game)
{
  if (game->info.crazy == MOD_BONJOUR)
    game->info.crazy = MOD_OK;
  else
    game->info.crazy = MOD_BONJOUR;
  return (1);
}

int		key_faq(t_game *game)
{
  if (game->info.crazy == MOD_FAQ)
    game->info.crazy = MOD_OK;
  else
    game->info.crazy = MOD_FAQ;
  return (1);
}

t_key		key_list[]=
  {
    {SDLK_LEFT, key_left},
    {SDLK_RIGHT, key_right},
    {SDLK_UP, key_up},
    {SDLK_DOWN, key_down},
    {SDLK_c, key_c},
    {SDLK_w, key_w},
    {SDLK_s, key_s},
    {SDLK_a, key_a},
    {SDLK_d, key_d},
    {SDLK_b, key_b},
    {SDLK_F1, key_faq},
    {SDLK_ESCAPE, key_escape},
    {0,0}
  };

int		key_func(t_game *game)
{
  int		i;
  int		retour;
  Uint8		*keystate;

  keystate = SDL_GetKeyState(NULL);
  i = 0;
  retour = 1;
  if (game->info.crazy == MOD_BEGIN)
    game->info.crazy = MOD_OK;
  while (key_list[i].keycode)
    {
      if (keystate[key_list[i].keycode])
	retour = key_list[i].func(game);
      i++;
    }
  return (retour);
}

/* Entre close et return
   TTF_CloseFont(game->font);
   TTF_Quit();
*/
int		exit_func(t_game *game)
{
  t_player	*player;
  t_team	*team;
  t_egg		*egg;

  printf("free party!\n");
  while (game->player)
    {
      player = game->player->next_pg;
      free(game->player);
      game->player = player;
    }
  while (game->team)
    {
      team = game->team->next;
      free(game->team);
      game->team = team;
    }
  while (game->egg)
    {
      egg = game->egg->next;
      free(game->egg);
      game->egg = egg;
    }
  free(game->serv.cbuf);
  close(game->serv.socket);
  return (0);
}
