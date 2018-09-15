/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:03:10 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/14 22:54:26 by cbrill           ###   ########.fr       */
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
	p->color = intcolor(255, 255, 255);
	p->click_x = -1;
	p->map = (t_tab2dint){ NULL, 0, 0 };
	if (!(p->mlx = mlx_init()) || !
		(p->win = mlx_new_window(p->mlx, p->map.c, p->map.r, "fdf")))
		return (deconstruct(p));
	return (p);
}

int		main(int c, char **v)
{
	t_mlxp	*p;

	if (c == 2)
	{
		if (!(p = construct()))
			nope("main.c:construct\tOOM or mlx error", -1);
		mapfromfile(v[1], p);
		if (p->map.r == 0)
			nope("map.c:getsize reports file error", -1);
		printf("\n%d\n\n", p->map.map[1][2]);
		mlx_key_hook(p->win, fdf_key_hook, p);
		mlx_mouse_hook(p->win, fdf_mouse_hook, p);
		mlx_expose_hook(p->win, fdf_expose_hook, p);
		mlx_string_put(p->mlx, p->win, 10, 10, p->color, "ESC: exit");
		mlx_loop(p->mlx);
	}
}
