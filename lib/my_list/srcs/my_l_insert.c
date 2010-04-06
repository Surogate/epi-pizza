/*
** my_l_insert.c for  in /u/epitech_2012s/chanio_f/cu/lib/my_list
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Nov 30 14:01:45 2009 florian chanioux
** Last update Sat Mar 20 18:16:06 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#include "my_list.h"

static t_list		*create_elem(void *element)
{
  t_list	*res;

  if ((res = malloc(sizeof(*res))) == NULL)
  {
    fprintf(stderr, strerror(errno));
    exit(EXIT_FAILURE);
  }
  res->data = element;
  res->next = NULL;
  return (res);
}

t_list		*my_l_insert(t_list *res, void *element)
{
  t_list	*elem;

  elem = create_elem(element);
  elem->next = res;
  return (elem);
}
