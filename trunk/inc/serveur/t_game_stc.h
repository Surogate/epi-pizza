/*
**	Header
*/

#ifndef		__T_GAME_STC_H__
# define	__T_GAME_STC_H__

typedef struct	s_vis
{
  struct s_vis	*next;
  int		level;
  t_map		*cas;
  int		num;
}		t_vision;

typedef struct
{
  int		dir;
  int		up_left;
  int		right;
}		t_dir_v;

typedef struct
{
  int		dir;
  int		dir_left;
  int		front;
  int		dir_right;
}		t_dir_m;

#endif		/*__T_GAME_STC_H__*/
