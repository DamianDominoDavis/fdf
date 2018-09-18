#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>

# define K_W (int)400
# define K_H (int)300

typedef struct s_vmap
{
	int			**m;
	int			rows;
	int			cols;
	int			bpp;
}				t_vmap;

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

void			drawline(int c[], t_mlxp *p);
void			drawmap(t_mlxp *mlx, t_vmap *map);
void			mlx_connect_hook(t_mlxp *p);
int				intcolor(int r, int g, int b);
int				nope(char *str, int rval);
int				main(int c, char **v);
int				map_load(t_vmap *map, char *path);
void			map_destroy(t_vmap *map);
void			mlx_destroy(t_mlxp *p);
int				mlx_create(t_mlxp *p, t_vmap *map);

#endif
