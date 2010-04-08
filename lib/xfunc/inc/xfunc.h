/*
** xfunc.h for  in /u/epitech_2012s/chanio_f/cu/rendu/c/my_nm
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Feb 24 15:36:40 2010 Florian Chanioux
** Last update Thu Apr  8 15:05:15 2010 Florian Chanioux
*/

#ifndef		__MY_H__
#define		__MY_H__

#include <sys/types.h>

/* GESTION ERREUR */

void		my_error(char *str);
void		prt_err(char *str);

/* COMMANDE SYSTEME */

void		*xmalloc(size_t size);
void		*xrealloc(void *ptr, size_t size);
ssize_t		xwrite(int fd, void *buff, size_t nbytes);
ssize_t		xread(int fd, void *buff, size_t nbytes);
int		xopen(char *path, int flags, ...);
int		xclose(int d);

#endif		/* __MY_H__ */
