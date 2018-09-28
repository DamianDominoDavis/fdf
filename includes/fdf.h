/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:57:21 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/27 16:08:27 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>

# define K_W ((int)800)
# define K_H ((int)600)
# define X_ORI ((int)(K_W / 2))
# define Y_ORI ((int)(K_H / 2))
# define K_WHITE ((int)16777215)
# define K_SCALE ((double)1.5)

typedef struct	s_vox
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_vox;

typedef struct	s_vmap
{
	t_vox		*m;
	int			rows;
	int			cols;
	double		scale;
	double		tile;
}				t_vmap;

typedef struct	s_mlxp
{
	void		*mlx;
	void		*win;
	void		*map;
}				t_mlxp;

void			*mlx_init();
int				nope(char *str, int rval);
int				mlx_create(t_mlxp *p, t_vmap *map);
void			mlx_destroy(t_mlxp *p);
int				map_create(t_vmap *map, char *path);
void			map_destroy(t_vmap *map);
int				gradient(int start, int finish, int steps);
void			draw_line(t_mlxp *p, t_vox a, t_vox b);
void			draw_map(t_mlxp *mlx, t_vmap *map);
void			fdf_connect_hook(t_mlxp *p);

#endif
