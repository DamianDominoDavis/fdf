/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:53:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/17 11:23:11 by cbrill           ###   ########.fr       */
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

static int	fdf_mouse_hook(int button, int x, int y, t_mlxp *p)
{
	static int sx;
	static int sy;
	ft_putstr(button == 1 ? "lclick:" : "rclick:");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	if (sx >= 0)
	{
		ft_putendl("(lined)");
		drawline((int[]){x, y, sx, sy}, p);
		sx = -1;
	}
	else
	{
		ft_putendl("(saved)");
		sx = x;
		sy = y;
	}
	return (0);
}

static int	fdf_expose_hook(t_mlxp *p)
{
	(void)p;
	ft_putendl("expose");
	return (0);
}

void	mlx_connect_hook(t_mlxp *p)
{
	ft_putendl("connecting...");
	mlx_key_hook(p->win, fdf_key_hook, p);
	ft_putendl("connecting...");
	mlx_mouse_hook(p->win, fdf_mouse_hook, p);
	mlx_expose_hook(p->win, fdf_expose_hook, p);
	mlx_string_put(p->mlx, p->win, 10, 10, p->color, "ESC: exit");
	mlx_loop(p->mlx);
	ft_putstr("connected");
}
