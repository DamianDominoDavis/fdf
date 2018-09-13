/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:53:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/12 18:35:13 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_hook(int key, t_mlxp *p)
{
	ft_putstr("key:");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
	{
		deconstruct(p);
		exit(1);
	}
	return (0);
}

int	fdf_mouse_hook(int button, int x, int y, t_mlxp *p)
{
	ft_putstr(button == 1 ? "lclick:" : "rclick");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	if (p->click_x >= 0)
	{
		ft_putendl("(lined)");
		drawline((int[]){p->click_x, p->click_y, x, y}, p);
		p->click_x = -1;
	}
	else
	{
		ft_putendl("(saved)");
		p->click_x = x;
		p->click_y = y;
	}
	return (0);
}

int	fdf_expose_hook(t_mlxp *p)
{
	(void)p;
	ft_putendl("expose");
	return (0);
}
