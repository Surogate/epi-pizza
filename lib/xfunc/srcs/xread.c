/*
** xread.c for  in /u/epitech_2012s/chanio_f/cu/rendu/piscine/TJour_05
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sun Nov 22 11:46:05 2009 florian chanioux
** Last update Sat Apr  3 18:11:51 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "xfunc.h"

ssize_t 	xread(int fd, void *buff, size_t nbytes)
{
  ssize_t		size;

  size = read(fd, buff, nbytes);
  if (size < 0)
     prt_err("read failed");
  return (size);
}
