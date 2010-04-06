/*
** xwrite.c for  in /u/epitech_2012s/chanio_f/cu/rendu/piscine/TJour_05
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sun Nov 22 11:42:17 2009 florian chanioux
** Last update Wed Feb 24 15:29:49 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "xfunc.h"

ssize_t 	xwrite(int fd, void *buff, size_t nbytes)
{
  ssize_t		size;

  size = write(fd, buff, nbytes);
  return (size);
}
