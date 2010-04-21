/* pick.c    */

/* E. Angel, Interactive Computer Graphics */
/* A Top-Down Approach with OpenGL, Third Edition */
/* Addison-Wesley Longman, 2003 */

/* demonstrates picking used selection mode */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
# include	<GL/freeglut_std.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		processHits(GLint hits, GLuint buffer[])
{
  GLint i, j, numberOfNames;
  GLuint names, *ptr, minZ,*ptrNames;

  ptr = (GLuint *) buffer;
  minZ = 0xffffffff;
  for (i = 0; i < hits; i++)
  {
    names = *ptr;
    ptr++;
    if (*ptr < minZ)
    {
      numberOfNames = names;
      minZ = *ptr;
      ptrNames = ptr+2;
    }
    ptr += names+2;
  }
  if (numberOfNames > 0)
  {
    printf ("You picked case  ");
    ptr = ptrNames;
    for (j = 0; j < numberOfNames; j++,ptr++)
      printf ("%d ", *ptr);
  }
  else
    printf("You didn't click on case");
  printf ("\n");
}

void		picking_mouse(t_game *game, int x, int y)
{
  GLuint	selectBuf[BUFSIZE];
  GLint		hits;
  GLint		viewport[4];
  GLfloat	ratio;

  glSelectBuffer (BUFSIZE, selectBuf);
  glGetIntegerv(GL_VIEWPORT,viewport);
  glRenderMode(GL_SELECT);
  glInitNames();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
/*  create 5x5 pixel picking region near cursor location      */
  gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 5, 5, viewport);
  ratio = (GLfloat)(viewport[2] / viewport[3]);
  gluPerspective(WIN_FOC, ratio, WIN_NEAR, WIN_FAR);
  glMatrixMode(GL_MODELVIEW);
  draw_gl(game, GL_SELECT);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  hits = glRenderMode(GL_RENDER);
  if (hits != 0)
    processHits(hits, selectBuf);
}
