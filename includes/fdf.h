/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:14:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 21:30:22 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>

# define K_BPP (int)24

typedef struct	s_mlxp
{
	void		*mlx;
	void		*win;
	int			click_x;
	int			click_y;
	int			width;
	int			height;
	int			bpp;
	int			**map;
}				t_mlxp;

void			*mlx_init();

/*
** src/main.c
*/
int				nope(char *str, int rval);
void			*deconstruct(t_mlxp *mlx);
t_mlxp			*construct(void);

/*
** src/hooks.c
*/
int				fdf_key_hook(int key, t_mlxp *p);
int				fdf_mouse_hook(int button, int x, int y, t_mlxp *p);
int				fdf_expose_hook(t_mlxp *p);

/*
** src/drawline.c
*/
void			drawline(int c[], t_mlxp *p);

/*
** others
*/
int				intcolor(int r, int g, int b);
int				**mapfromfile(int fd);
void			loadimage(char *img, t_mlxp *p);
int				setbuffwidth(int fd);
int				**mapfromfile(int fd);

#endif
