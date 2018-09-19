/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:42:45 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/18 13:12:08 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawlinelo(t_mlxp *p, t_xyz a, t_xyz b)
{
	int dx;
	int dy;
	int yi;
	int d;

	dx = b.x - a.x;
	dy = (b.y - a.y > 0) ? (b.y - a.y) : (a.y - b.y);
	yi = (b.y - a.y > 0) ? 1 : -1;
	d = 2 * dy - dx;
	while (a.x != b.x)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
		if (d > 0)
		{
			a.y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		a.x += (b.x > a.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
}

static void	drawlinehi(t_mlxp *p, t_xyz a, t_xyz b)
{
	int dx;
	int dy;
	int xi;
	int d;

	dx = (b.x - a.x > 0) ? (b.x - a.x) : (a.x - b.x);
	dy = b.y - a.y;
	xi = (b.x - a.x > 0) ? 1 : -1;
	d = 2 * dx - dy;
	while (a.y != b.y)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
		if (d > 0)
		{
			a.x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		a.y += (b.y > a.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
}

static void	drawlinevl(t_mlxp *p, t_xyz a, t_xyz b)
{
	while (a.y != b.y)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
		a.y += (a.y < b.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
}

static void	drawlinehl(t_mlxp *p, t_xyz a, t_xyz b)
{
	while (a.x != b.x)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
		a.x += (a.x < b.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, colorasdepth(a.c));
}

void		drawline(t_mlxp *p, t_xyz a, t_xyz b)
{
	if (a.x == b.x)
		drawlinevl(p, a, b);
	else if (a.y == b.y)
		drawlinehl(p, a, b);
	else if (fabs(b.y - a.y) < fabs(b.x - a.x))
		(a.x > b.x) ?
			drawlinelo(p, b, a) : drawlinelo(p, a, b);
	else
		(a.y > b.y) ?
			drawlinehi(p, b, a) : drawlinehi(p, a, b);
}
