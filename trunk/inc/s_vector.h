/*
** s_vector for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 11:07:55 2010 francois1 ancel
** Last update Mon Mar 22 06:35:47 2010 lucas1 santamaria
*/

#ifndef			__S_LLIST_INCLUDED__
# define		__S_LLIST_INCLUDED__

typedef struct		s_llist
{
  void			*strct;
  struct s_llist	*nxt;
  struct s_llist	*prv;
}			t_llist;

#endif			/*__S_LLIST_INCLUDED__*/

#ifndef		__S_VECTOR_INCLUDED__
# define	__S_VECTOR_INCLUDED__

typedef struct	s_vector
{
  t_llist	*start;
  int		size;
  t_llist	*gns;
  int		gns_pos;
  int		(*push_back)();
  int		(*push_front)();
  void		*(*at)();
  int		(*insert)();
  void		*(*delete)();
  void		*(*delete_by)();
  void		(*destruc)();
  void		*(*getnxts)();
  void		(*erase)();
  void		(*insert_sort)();
  int		(*find_pos)();
  void		*(*find_by)();
  void		(*swap)();
}		t_vector;

t_vector	*vector_new();
void		vector_init(t_vector *new);

#endif		/*__S_VECTOR_INCLUDED__*/

/*
## int		push_back(t_vector *vec, void *strct)
Rajoute la fin du vector le contenue pointer par strct
renvoie `EXIT_SUCCESS` ou `EXIT_FAILURE`

## int		push_front(t_vector *vec, void *strct)
Rajoute au debut du vector le contenue pointer par strct
renvoie `EXIT_SUCCESS` ou `EXIT_FAILURE`

## void		*at(t_vector *vec, int at)
Renvoie le contenue qui est a la position `at`
si la position est incorrecte, renvoie NULL

## void	       	*getnxts(t_vector *vec)
Renvoie successivement les structure contenue dans le vector
la structure est stocker dans le pointeur statique `gns`
et la position actuelle est stocker dans gns_pos
La fin de la liste est signaler par le renvoie NULL

## int		insert(t_vector *vec, void *strct, int at)
Rajoute apres l'element qui est a la position `at` 
du vector le contenue pointer par strct
renvoie `EXIT_SUCCESS` ou `EXIT_FAILURE`

## void		*delete(t_vector *vec, int at)
Delele le conteneur a la position `at` mais pas le contenue
le contenue est renvoyer si l'operation est reussi, sinon NULL

## void		destruc(t_vector *vec, void strct_des())
Delete la liste et son contenue grace a la fonction destruct, 
destruct doit etre de la forme :

void votre_nom(votre struct *strct);

## void		erase(t_vector *vec, int at, void (*destruct)())
Delete le conteneur a la position `at` et le contenue est detruit
grace a la fonction destruct, destruct doit etre de la forme :

void votre_nom(votre_struct *strct);

## void		insert_sort(t_vector *vec, void *strct, int (*sort_fct)())

insert le pointeur `strct` suivant la fonction `sort_fct`
la fonction `sort_fct` doit etre de la forme :

int sort_fct(votre_struct *inline, votre_struct *insert)

inline correspond au struct contenue dans le vector
insert la struct que vous voulez insert
elle doit renvoyer un int >=1 tant que l'on ne doit pas insert la strct

## int		find_pos(t_vector *vec, void *strct, int (*find_fct)())

Renvoie la position de la strct dont la fonction find_fct renvoie 1 ou plus
find_fct doit etre de la forme :

int find_fct(votre_struct *inline, (void *)strct)

inline correspond au struct contenue dans le vector
si aucune position valide est trouver, la fonction renvoie -1
*/
