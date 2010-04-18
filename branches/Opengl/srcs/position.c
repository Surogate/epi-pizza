/* pick.c    */

/* E. Angel, Interactive Computer Graphics */
/* A Top-Down Approach with OpenGL, Third Edition */
/* Addison-Wesley Longman, 2003 */

/* demonstrates picking used selection mode */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include "SDL_ttf.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut_std.h>
#endif

#include "define.h"
#include "struct.h"
#include "proto.h"

void init()
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void drawObjects(GLenum mode)
{
	if(mode == GL_SELECT)
	  glLoadName(6);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-0.5, -0.5, 1.0, 1.0);
	if(mode == GL_SELECT)
	  glLoadName(2);
	glColor3f(0.0, 0.0, 1.0);
	glRectf(-1.0, -1.0, 0.5, 0.5);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawObjects(GL_RENDER);
	glFlush();
}

/*  processHits prints out the contents of the 
 *  selection array.
 */
void processHits (GLint hits, GLuint buffer[])
{
   unsigned int i, j;
   GLuint names, *ptr;

   printf ("hits = %d\n", hits);
   ptr = (GLuint *) buffer; 
   for (i = 0; i < hits; i++) {	/*  for each hit  */
      names = *ptr;
	  ptr+=3;
      for (j = 0; j < names; j++) { /*  for each name */
         if(*ptr==1) printf ("red rectangle\n");
         else printf ("blue rectangle\n");
         ptr++;
      }
      printf ("\n");
   }
}

#define SIZE 512

void mouse(t_game *game, int x, int y)
{
   GLuint selectBuf[SIZE];
   GLint hits;
   GLint viewport[4];

   glGetIntegerv (GL_VIEWPORT, viewport);

   /* create selection buffer*/
   glSelectBuffer (SIZE, selectBuf);
   /* choose Selection mode */
   glRenderMode(GL_SELECT);

   glInitNames();
   glPushName(0);

   glMatrixMode (GL_PROJECTION);
   glPushMatrix ();
   glLoadIdentity ();
/*  create 5x5 pixel picking region near cursor location	
    within viewport */

   gluPickMatrix ((GLdouble) x, (GLdouble) (viewport[3] - y), 
                  5.0, 5.0, viewport);
   gluOrtho2D (-2.0, 2.0, -2.0, 2.0);

   /* draw_map(game, GL_SELECT);*/

   glMatrixMode (GL_PROJECTION);
   glPopMatrix ();
   glFlush ();

   hits = glRenderMode (GL_RENDER);
   processHits (hits, selectBuf);

}


void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D (-2.0, 2.0, -2.0, 2.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

/* Main Loop */
/*
  int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutReshapeFunc (reshape);
   glutDisplayFunc(display);
   glutMouseFunc (mouse);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0; 
}
*/
