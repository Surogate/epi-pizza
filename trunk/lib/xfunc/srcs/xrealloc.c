/*
** xrealloc.c for  in /home/Ayden/Epitech/Projet/my_ftp
** 
** Made by Florian Chanioux
** Login   <Ayden@epitech.net>
** 
** Started on  Sat Mar 13 03:07:50 2010 Florian Chanioux
** Last update Sat Apr  3 18:16:08 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#include "xfunc.h"

void		*xrealloc(void *ptr, size_t size)
{
  void		*mall;

  mall = realloc(ptr, size);
  if (mall == 0)
    prt_err("realloc failed");
  if (ptr == NULL)
    memset(mall, 0, size);
  return (mall);
}
