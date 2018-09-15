/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:14:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/14 22:55:32 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
#include <stdio.h>

# define K_BPP (int)24

typedef struct	s_mlxp
{
	void		*mlx;
	void		*win;
	int			click_x;
	int			click_y;
	int			bpp;
	t_tab2dint	map;
	int			color;
}				t_mlxp;

/*
** required by minilibx
*/
void			*mlx_init();

/*
** main.c
*/
int				nope(char *str, int rval);
void			*deconstruct(t_mlxp *p);
t_mlxp			*construct(void);

/*
** hooks.c
*/
int				fdf_key_hook(int key, t_mlxp *p);
int				fdf_mouse_hook(int button, int x, int y, t_mlxp *p);
int				fdf_expose_hook(t_mlxp *p);

/*
** drawline.c
*/
void			drawline(int c[], t_mlxp *p);

/*
** others
*/
int				intcolor(int r, int g, int b);
int				setbuffwidth(int fd);

/*
** map.c
*/
void			mapfromfile(char *path, t_mlxp *p);

#endif
