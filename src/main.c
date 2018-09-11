/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:03:10 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/11 01:56:27 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nope(char *str, int rval)
{
	(void)str;
	return (rval);
}

void	*deconstruct(t_mlxp *p)
{
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	ft_memdel((void **)&p);
	return (NULL);
}

t_mlxp	*construct(void)
{
	t_mlxp	*p;

	if (!(p = ft_memalloc(sizeof(t_mlxp))))
		return (NULL);
	p->width = 400;
	p->height = 300;
	p->color = intcolor(255, 255, 255);
	p->click_x = -1;
	if (!(p->mlx = mlx_init()) || !
		(p->win = mlx_new_window(p->mlx, p->width, p->height, "fdf")))
		return (deconstruct(p));
	return (p);
}

void	loadimage(char *img, t_mlxp *p)
{
	mlx_new_image(p->mlx, p->width, p->height);
	(void)img;
}

int		main(void)
{
	t_mlxp *p;

	p = construct();
	mlx_key_hook(p->win, fdf_key_hook, p);
	mlx_mouse_hook(p->win, fdf_mouse_hook, p);
	mlx_string_put(p->mlx, p->win, 10, 10, p->color, "ESC: exit");
	mlx_loop(p->mlx);
}
