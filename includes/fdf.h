#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>
#include <stdio.h>

# define K_W ((int)800)
# define K_H ((int)600)
# define X_ORI ((int)(K_W * 0.25))
# define Y_ORI ((int)(K_H * 0.8))
# define K_SCALE ((double)1.0)

typedef struct	s_vox
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_vox;

typedef struct s_vmap
{
	t_vox		*m;
	int			rows;
	int			cols;
	double		scale;
	double		tile;
}				t_vmap;

typedef struct s_view
{
	int			mindepth;
	int			maxdepth;
	int			scale;
	double		x;
	double		y;
	int			marginx;
	int			marginy;
}				t_view;

typedef struct	s_mlxp
{
	void		*mlx;
	void		*win;
	int			color;
	t_vmap		*map;
}				t_mlxp;

/*
** required by minilibx
*/
void			*mlx_init();

int	intcolor(int r, int g, int b);
int	colorasdepth(int c);
void		draw_line(t_mlxp *p, t_vox a, t_vox b);
void	draw_map(t_mlxp *mlx, t_vmap *map);
t_vox	*vox_get(t_vmap *map, int x, int y);
t_vox	*vox_proj(t_vmap *map, t_vox *dst, t_vox *src);
t_vox	vox_trunc(t_vox p);
void	fdf_connect_hook(t_mlxp *p);
int		nope(char *str, int rval);
int		main(int c, char **v);
int	map_load(t_vmap *map, char *path);
void	map_destroy(t_vmap *map);
void	mlx_destroy(t_mlxp *p);
int		mlx_create(t_mlxp *p);
int		view_create(t_view *v);

#endif
