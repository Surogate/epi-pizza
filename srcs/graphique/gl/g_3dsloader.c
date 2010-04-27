/*
 * ---------------- www.spacesimulator.net --------------
 *   ---- Space simulators and 3d engine tutorials ----
 *
 * Author: Damiano Vitulli <info@spacesimulator.net>
 *
 * ALL RIGHTS RESERVED
 *
 *
 * Tutorial 4: 3d engine - 3ds models loader
 *
 * Include File: 3dsloader.cpp
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include "graphique/3dsloader.h"


/**********************************************************
 *
 * FUNCTION Load3DS (obj_type_ptr, char *)
 *
 * This function loads a mesh from a 3ds file.
 * Please note that we are loading only the vertices, polygons and mapping lists.
 * If you need to load meshes with advanced features as for example:
 * multi objects, materials, lights and so on, you must insert other chunk parsers.
 *
 *********************************************************/

char			Load3DS (obj_type_ptr p_object, const char *p_filename)
{
  int			i;
  FILE			*l_file;
  unsigned short	l_chunk_id;
  unsigned int		l_chunk_lenght;
  unsigned char		l_char; 
  unsigned short	l_qty;
  unsigned short	l_face_flags;
  struct stat		filestat;
  unsigned int		bkText = p_object->id_texture;
  float			scale[3];
  long taille;

  scale[0] = p_object->scale[0];
  scale[1] = p_object->scale[1];
  scale[2] = p_object->scale[2];
  memset(p_object, 0, sizeof(*p_object));
  p_object->id_texture = bkText;
  p_object->scale[0] = scale[0];
  p_object->scale[1] = scale[1];
  p_object->scale[2] = scale[2];
  if ((l_file = fopen(p_filename, "rb")) == NULL)
    return 0;
  stat(p_filename, &filestat);
  while ((taille = ftell(l_file)) < (filestat.st_size))
  {
    fread (&l_chunk_id, 2, 1, l_file);
    fread (&l_chunk_lenght, 4, 1, l_file);
    switch (l_chunk_id)
    {
    case 0x4d4d:
      break;
    case 0x3d3d:
      break;
    case 0x4000:
      i=0;
      do
      {
        fread (&l_char, 1, 1, l_file);
        p_object->name[i]=l_char;
        i++;
      }
      while(l_char != '\0' && i<20);
      break;
      case 0x4100:
      break;
      case 0x4110:
      fread (&l_qty, sizeof (unsigned short), 1, l_file);
      p_object->vertices_qty = l_qty;
      i = -1;
      while (++i < l_qty)
      {
        fread (&p_object->vertex[i].x, sizeof(float), 1, l_file);
        fread (&p_object->vertex[i].y, sizeof(float), 1, l_file);
        fread (&p_object->vertex[i].z, sizeof(float), 1, l_file);
      }
      break;
      case 0x4120:
      fread (&l_qty, sizeof (unsigned short), 1, l_file);
      p_object->polygons_qty = l_qty;
      i = -1;
      while (++i < l_qty)
      {
        fread (&p_object->polygon[i].a, sizeof (unsigned short), 1, l_file);
        fread (&p_object->polygon[i].b, sizeof (unsigned short), 1, l_file);
        fread (&p_object->polygon[i].c, sizeof (unsigned short), 1, l_file);
        fread (&l_face_flags, sizeof (unsigned short), 1, l_file);
      }
      break;
    case 0x4140:
      fread (&l_qty, sizeof (unsigned short), 1, l_file);
      i = -1;
      while (++i < l_qty)
      {
        fread (&p_object->mapcoord[i].u, sizeof (float), 1, l_file);
        fread (&p_object->mapcoord[i].v, sizeof (float), 1, l_file);
      }
      break;
      default:
      fseek(l_file, l_chunk_lenght-6, SEEK_CUR);
    }
  }
  fclose(l_file);
  return (1);
}

void		draw_mesh(obj_type *mesh)
{
  int		l_index;

  glBindTexture(GL_TEXTURE_2D, mesh->id_texture);
  glColor3f(1.0f, 1.0f, 1.0f);
  glPushMatrix();
  glScalef(mesh->scale[0], mesh->scale[1], mesh->scale[2]);
  glBegin(GL_TRIANGLES);
  l_index = -1;
  while (++l_index < mesh->polygons_qty)
  {
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].a ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].a ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].a ].x,
	       mesh->vertex[ mesh->polygon[l_index].a ].y,
	       mesh->vertex[ mesh->polygon[l_index].a ].z);
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].b ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].b ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].b ].x,
	       mesh->vertex[ mesh->polygon[l_index].b ].y,
	       mesh->vertex[ mesh->polygon[l_index].b ].z);
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].c ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].c ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].c ].x,
	       mesh->vertex[ mesh->polygon[l_index].c ].y,
	       mesh->vertex[ mesh->polygon[l_index].c ].z);
  }
  glEnd();
  glPopMatrix();
}
