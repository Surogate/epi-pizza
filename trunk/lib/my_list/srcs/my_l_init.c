/*
** my_init_list.c for  in /u/epitech_2012s/chanio_f/cu/lib/my_list/srcs
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Nov 30 12:30:14 2009 florian chanioux
** Last update Sat Mar 20 18:05:46 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_list.h"

t_list          *my_l_init()
{
  t_list	*res;

  if ((res = malloc(sizeof(res))) == 0)
  {
    fprintf(stdout, "%s", strerror(errno));
    exit(1);
  }
  res->data = NULL;
  res->next = NULL;
  return (0);
}
