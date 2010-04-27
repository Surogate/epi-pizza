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
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void	init_fog(int fog, GLint fogmode)
{
  static float		fog_color[4] = {0.0, 0.5, 0.9, 1.0};

  if (fog == 1)
  {
    puts("FOG ON");
    glEnable(GL_FOG);
    glFogi (GL_FOG_MODE, fogmode);
    glFogfv(GL_FOG_COLOR, fog_color);
    glFogf(GL_FOG_DENSITY, 0.3);
    glFogf(GL_FOG_START, 400.0);
    glFogf(GL_FOG_END, 500.0);
    glClearColor(0.0, 0.5, 0.9, 1.0);
  }
  else
    puts("FOG OFF");
}

void	init_aliasing(int aliasing)
{
  if (aliasing == 1)
  {
    puts("ALIASING ON");
    glEnable(GL_POLYGON_SMOOTH);
  }
  else
  {
    puts("ALIASING OFF");
    glDisable(GL_POLYGON_SMOOTH);
  }
}