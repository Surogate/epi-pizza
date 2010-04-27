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

void		draw_trantorien_epileptique(int nb)
{
  static int i = 0;

  i %= 360;
  glPushMatrix();
  glTranslated((CASE_H / 2), (CASE_W / 2), 0);
  if (nb != 0)
    glRotatef(i++, 0 ,0 ,1);
  glCallList(TOTORO + random() % LVLMAX);
  glPopMatrix();
}

void		crazy_mod(t_game *game)
{
  int		ref;
  int		x;
  int		y;

  ref = game->map.h * game->map.w;
  x = -1;
  while (++x < game->map.h)
  {
    y = -1;
    while (++y < game->map.w)
    { 
      glPushMatrix();
      glTranslated(y * CASE_H, x * CASE_W, 0);
      draw_trantorien_epileptique(1);
      glPopMatrix();
    }
  }
}
