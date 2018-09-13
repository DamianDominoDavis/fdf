/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:14:39 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/12 18:41:00 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define K_WIDTH (int)500
# define K_HEIGHT (int)500

typedef struct	s_mlxp
{
	void		*mlx;
	void		*win;
	int			click_x;
	int			click_y;
	int			color;
	int			width;
	int			height;
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

int				intcolor(int r, int g, int b);

#endif
