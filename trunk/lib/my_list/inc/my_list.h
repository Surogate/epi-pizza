/*
** my_list.h for  in /u/epitech_2012s/chanio_f/cu/lib/my_list/inc
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Nov 30 12:35:43 2009 florian chanioux
** Last update Sun Mar 21 00:14:48 2010 Florian Chanioux
*/

#ifndef                 __MY_LIST_H__
#define                 __MY_LIST_H__

typedef struct          s_list
{
  void                  *data;
  struct s_list         *next;
}                       t_list;

t_list                  *my_l_init();
t_list                  *my_l_insert(t_list *res, void *element);
t_list		        *my_l_rm(t_list *begin, void *data, int (*func)());
int                     my_l_rm_all(t_list **begin, void *data_ref,
                                    int (*cmp)());
int			my_l_rm_iem(t_list **begin, int iem,
				    void (*func)());
int                     my_l_sort(t_list **begin,int (*cmp)());
int                     my_l_size(t_list *begin);
t_list                  *my_l_params(int ac,char **av);
int                     my_l_apply(t_list *begin, int (*f)());
int                     my_l_apply_iem(t_list *begin, int iem, int (*f)());
void                    my_l_free(t_list *list, void (*func)());
int                     my_l_rev(t_list **begin);
void                    *my_l_iem(t_list *begin, int iem);

#endif                  /* __MY_LIST_H__ */
