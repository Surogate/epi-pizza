/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sun Apr 18 20:57:17 2010 Florian Chanioux
*/

#ifndef		DEFINE_H
# define	DEFINE_H

# define	WIN_W		800
# define	WIN_H		600
# define	WIN_COLOR	32

# define	CASE_W		32
# define	CASE_H		32
# define	MAP_CW		100
# define	MAP_CH		100

# define	MAP_CASE	1


# define	FONT_DIR	"./font/MONACO.ttf"
# define	MFONT_SIZE	7
# define	FULLSCREEN	0

# define	CAM_Z		(200)

# define	CAM_O_X		((CASE_W * MAP_CW) / 2)
# define	CAM_O_Y		((CASE_H * MAP_CH) / 2)
# define	CAM_O_Z		(0)


#endif		/*DEFINE_H*/
