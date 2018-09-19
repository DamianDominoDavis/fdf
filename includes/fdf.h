#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>

# define K_W (int)2048
# define K_H (int)1300

typedef struct	s_xyz
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_xyz;

typedef struct s_vmap
{
	t_xyz		**m;
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

int				intcolor(int r, int g, int b);
int				colorasdepth(int c);
void			drawline(t_mlxp *p, t_xyz a, t_xyz b);
void			drawmap(t_mlxp *mlx, t_vmap *map, t_view *v);
t_xyz			pget(t_vmap *map, int x, int y);
t_xyz			project_vector(t_view *v, t_vmap *map, t_xyz p);
t_xyz			rotate(t_xyz p, t_view *r);
void			fdf_connect_hook(t_mlxp *p);
int				nope(char *str, int rval);
int				map_load(t_vmap *map, char *path);
void			map_destroy(t_vmap *map);
void			mlx_destroy(t_mlxp *p);
int				mlx_create(t_mlxp *p, t_vmap *map);

#endif
