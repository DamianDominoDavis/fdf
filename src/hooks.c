/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:53:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/27 17:17:57 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_key_hook(int key, t_mlxp *p)
{
	if (key == 53)
		mlx_destroy(p);
	return (0);
}

static int	fdf_mouse_hook(int button, int cx, int cy, t_mlxp *p)
{
	static int		alternate;
	static t_vox	click;
	t_vox			clock;

	if (alternate)
	{
		clock.x = cx;
		clock.y = cy;
		clock.c = K_WHITE;
		draw_line(p, click, clock);
		alternate = 0;
	}
	else
	{
		click.x = cx;
		click.y = cy;
		click.c = K_WHITE;
		alternate = 1;
	}
	return (0);
}

void		fdf_connect_hook(t_mlxp *p)
{
	mlx_hook(p->win, 2, 5, fdf_key_hook, p);
	mlx_mouse_hook(p->win, fdf_mouse_hook, p);
	mlx_string_put(p->mlx, p->win, 10, K_H - 30, K_WHITE, "ESC: exit");
	mlx_loop(p->mlx);
}
