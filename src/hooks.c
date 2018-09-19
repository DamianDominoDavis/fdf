/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:53:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/18 11:50:10 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_key_hook(int key, t_mlxp *p)
{
	ft_putstr("key:");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		mlx_destroy(p);
	return (0);
}

static int	fdf_mouse_hook(int button, int cx, int cy, t_mlxp *p)
{
	static int alternate;
	static t_xyz click;
	t_xyz clock;
	ft_putstr(button == 1 ? "lclick:" : "rclick:");
	ft_putnbr(cx);
	ft_putchar(',');
	ft_putnbr(cy);
	if (alternate)
	{
		ft_putendl("(saved)");
		click.x = cx;
		click.y = cy;
		alternate = 1;
	}
	else
	{
		ft_putendl("(lined)");
		clock.x = cx;
		clock.y = cy;
		drawline(p, click, clock);
		alternate = 0;
	}
	return (0);
}

static int	fdf_expose_hook(t_mlxp *p)
{
	(void)p;
	ft_putendl("expose");
	return (0);
}

void	fdf_connect_hook(t_mlxp *p)
{
	mlx_key_hook(p->win, fdf_key_hook, p);
	mlx_mouse_hook(p->win, fdf_mouse_hook, p);
	mlx_expose_hook(p->win, fdf_expose_hook, p);
	mlx_string_put(p->mlx, p->win, 10, 10, p->color, "ESC: exit");
	mlx_loop(p->mlx);
}
