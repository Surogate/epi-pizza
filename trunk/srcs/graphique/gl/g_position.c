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
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
# include	<GL/freeglut_std.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

static int	calc_res(GLuint *ptr[2],
			 GLint numberOfNames)
{
  int j;
  int res;

  res = -100;
  if (numberOfNames > 0)
  {
    printf ("You picked element #:");
    ptr[0] = ptr[1];
    j = 0;
    while (j < numberOfNames)
    {
      printf("%d", (res = *(ptr[0])));
      j++;
      ptr[0]++;
    }
  }
  else
    printf("You didn't click on case");
  printf("\n");
  return (res);
}

static int	processHits(GLint hits, GLuint buffer[])
{
  GLint i;
  GLint numberOfNames;
  GLuint names;
  GLuint minZ;
  GLuint *ptr[2];

  ptr[1] = 0;
  ptr[0] = (GLuint *)buffer;
  minZ = 0xffffffff;
  i = -1;
  while (++i < hits)
  {
    names = *(ptr[0]);
    (ptr[0])++;
    if (*(ptr[0]) < minZ)
    {
      numberOfNames = names;
      minZ = *(ptr[0]);
      ptr[1] = ptr[0] + 2;
      printf("test test traitement hits: %d\n", *(ptr[1]));
    }
    printf("test  traitement hits: %d\n", *(ptr[1]));
    ptr[0] += names + 2;
    printf("traitement hits: %d\n", *(ptr[1]));
  }
  return (calc_res(ptr, numberOfNames));
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
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glInitNames();
  glLoadIdentity();
  gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 1, 1, viewport);
  ratio = (GLfloat)(viewport[2] / viewport[3]);
  gluPerspective(WIN_FOC, ratio, WIN_NEAR, WIN_FAR);
  glMatrixMode(GL_MODELVIEW);
  draw_gl(game, GL_SELECT);
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  hits = glRenderMode(GL_RENDER);
  if (hits != 0)
    game->map.select_c = processHits(hits, selectBuf);
}
