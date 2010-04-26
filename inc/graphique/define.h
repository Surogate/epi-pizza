/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 03:18:02 2010 Florian Chanioux
*/

#ifndef		DEFINE_H
# define	DEFINE_H

# define	FPS		30

# define	WIN_W		1024
# define	WIN_H		768

# define	WIN_FOC		70.0
# define	WIN_NEAR	1
# define	WIN_FAR		800.0

# define	WIN_BPP		32
# define	WIN_COLOR	32

# define	CASE_W		42
# define	CASE_H		42

# define	TOTORO		1
# define	TERRAIN		10
# define	INTER		20
# define	PICKING		30
# define	PSELECT		31
# define	TEAM		32
# define	RESS		40

enum {YELLOW, BLUE, GREEN, PINK, PURPLE, RED, BLACK, WHITE, CYAN};

# define	LVLMAX		8
# define	NBRESS		7

# define	FONT_DIR	"./font/MONACO.ttf"
# define	MFONT_SIZE	7
# define	FULLSCREEN	0

# define	CAM_Z		(200)

# define	CAM_MAX		300
# define	CAM_MIN		26

#define 	RENDER		1
#define 	SELECT		2
#define 	BUFSIZE 	1024
#endif		/*DEFINE_H*/
