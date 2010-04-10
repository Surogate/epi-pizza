/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/

#ifndef		STRUCT_H
# define	STRUCT_H

typedef struct	s_event
{
  Uint8		type;
  void		(*func)();
}		t_event;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

#endif		/*STRUCT_H*/
