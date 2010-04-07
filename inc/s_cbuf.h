/*
** cir_buf for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 10:42:20 2010 francois1 ancel
** Last update Mon Mar 22 06:25:00 2010 lucas1 santamaria
*/

#ifndef		__CIR_BUF_INCLUDED__
#define		__CIR_BUF_INCLUDED__

#define CBUFSIZ 1024

typedef struct	s_cbuf
{
  char		buf[CBUFSIZ + 1];
  unsigned int	cons;
  unsigned int	prod;
  int		use;
}		t_cbuf;

t_cbuf		*cbuf_new();
void		cbuf_init(t_cbuf *cbuf);

#endif		/*__CIR_BUF_INCLUDED__*/
