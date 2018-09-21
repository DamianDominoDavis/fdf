#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>

# define K_W ((int)400)
# define K_H ((int)300)
# define X_ORI (K_W / 2)
# define Y_ORI (K_H / 2)

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
	int			bpp;
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
void		drawline(t_mlxp *p, t_vox a, t_vox b);
void	drawmap(t_mlxp *mlx, t_vmap *map);
t_vox	*pget(t_vmap *map, int x, int y);
t_vox	*project(t_vox *dst, t_vox *src);
void	fdf_connect_hook(t_mlxp *p);
int		nope(char *str, int rval);
int		main(int c, char **v);
int	map_load(t_vmap *map, char *path);
void	map_destroy(t_vmap *map);
void	mlx_destroy(t_mlxp *p);
int		mlx_create(t_mlxp *p, t_vmap *map);
int		view_create(t_view *v);
#endif
