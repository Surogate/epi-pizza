/*
** test_opengl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 17:12:18 2010 Florian Chanioux
** Last update Sat Apr 24 08:11:36 2010 Florian Chanioux
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	"SDL_ttf.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		printAttributes()
{
  int		nAttr;
  int		i;
  int		attr[] = {SDL_GL_RED_SIZE, SDL_GL_BLUE_SIZE,
			  SDL_GL_GREEN_SIZE, SDL_GL_ALPHA_SIZE,
			  SDL_GL_BUFFER_SIZE, SDL_GL_DEPTH_SIZE };
  char		*desc[] = {"Red size: %d bits\n",
			   "Blue size: %d bits\n",
			   "Green size: %d bits\n",
			   "Alpha size: %d bits\n",
			   "Color buffer size: %d bits\n",
			   "Depth bufer size: %d bits\n"};
  int		value;

  nAttr = sizeof(attr) / sizeof(int);
  i = -1;
  while (++i < nAttr)
  {
    SDL_GL_GetAttribute(attr[i], &value);
    printf(desc[i], value);
  }
}
/*
static double mtime(void)
{
   struct timeval tk_time;
   struct timezone tz;

   gettimeofday(&tk_time, &tz);
   return (4294.967296 * tk_time.tv_sec + 0.000001 * tk_time.tv_usec);
}
*/
static double filter(double in, double *save)
{
        static double k1 = 0.9;
        static double k2 = 0.05;

        save[3] = in;
        save[1] = save[0]*k1 + k2*(save[3] + save[2]);
        save[0] = save[1];
        save[2] = save[3];
        return (save[1]);
}

void		timing()
{
  static double	th[4] = {0.0, 0.0, 0.0, 0.0};
  static double	t1 = 0.0;
  static double	t2 = 0.0;
  static double	t;
  char	num_str[128];

  t2 = SDL_GetTicks();
  t = t2 - t1;
  if(t > 0.0001) t = 1.0 / t;
  glDisable(GL_LIGHTING);
  glColor3f(1.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, WIN_W, 0, WIN_H, -10.0, 10.0);
  glRasterPos2f(5.0, 5.0);
  sprintf(num_str, "%0.2f Hz, %dx%d, VENDOR: ", filter(t, th), WIN_W, WIN_H);
  DrawStr(num_str);
  DrawStr(glGetString(GL_VENDOR));
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);
}


