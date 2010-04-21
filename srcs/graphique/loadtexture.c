/*
** loadtexture.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 17 21:15:54 2010 Florian Chanioux
** Last update Mon Apr 19 16:12:53 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <unistd.h>
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
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

static SDL_Surface	*flipSurface(SDL_Surface * surface)
{
  int			current_line;
  int			pitch;
  SDL_Surface		*fliped_surface;

  fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
					surface->w,surface->h,
					surface->format->BitsPerPixel,
					surface->format->Rmask,
					surface->format->Gmask,
					surface->format->Bmask,
					surface->format->Amask);
  SDL_LockSurface(surface);
  SDL_LockSurface(fliped_surface);
  pitch = surface->pitch;
  current_line = -1;
  while (++current_line < surface->h)
    memcpy(&((unsigned char* )fliped_surface->pixels)[current_line*pitch],
	   &((unsigned char* )surface->pixels)[(surface->h - 1  -
						current_line)*pitch],
	   pitch);
  SDL_UnlockSurface(fliped_surface);
  SDL_UnlockSurface(surface);
  return (fliped_surface);
}

GLuint			loadtexture(const char * filename,int useMipMap)
{
  GLuint		glID;
  SDL_Surface		*picture_surface = NULL;
  SDL_Surface		*gl_surface = NULL;
  SDL_Surface		*gl_fliped_surface = NULL;
  Uint32		rmask;
  Uint32		gmask;
  Uint32		bmask;
  Uint32		amask;
  SDL_PixelFormat	format;

  picture_surface = IMG_Load(filename);
  if (picture_surface == NULL)
    return (0);
  format = *(picture_surface->format);
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif
  format.BitsPerPixel = 32;
  format.BytesPerPixel = 4;
  format.Rmask = rmask;
  format.Gmask = gmask;
  format.Bmask = bmask;
  format.Amask = amask;
  gl_surface = SDL_ConvertSurface(picture_surface,&format,SDL_SWSURFACE);
  gl_fliped_surface = flipSurface(gl_surface);
  glGenTextures(1, &glID);
  glBindTexture(GL_TEXTURE_2D, glID);
  if (useMipMap)
  {
    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, gl_fliped_surface->w,
		      gl_fliped_surface->h, GL_RGBA,GL_UNSIGNED_BYTE,
		      gl_fliped_surface->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
		    GL_LINEAR_MIPMAP_LINEAR);
  }
  else
  {
    glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_fliped_surface->w,
		 gl_fliped_surface->h, 0, GL_RGBA,GL_UNSIGNED_BYTE,
		 gl_fliped_surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  }
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  SDL_FreeSurface(gl_fliped_surface);
  SDL_FreeSurface(gl_surface);
  SDL_FreeSurface(picture_surface);
  return (glID);
}
