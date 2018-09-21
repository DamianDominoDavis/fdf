/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:42:45 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/21 16:11:11 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static void	gentle(t_mlxp *p, t_vox a, t_vox b)
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
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
		if (d > 0)
		{
			a.y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		a.x += (b.x > a.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
}

static void	steep(t_mlxp *p, t_vox a, t_vox b)
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
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
		if (d > 0)
		{
			a.x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		a.y += (b.y > a.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
}

static void	vertical(t_mlxp *p, t_vox a, t_vox b)
{
	while (a.y != b.y)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
		a.y += (a.y < b.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
}

static void	horizontal(t_mlxp *p, t_vox a, t_vox b)
{
	while (a.x != b.x)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
		a.x += (a.x < b.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, p->color);
}

void		draw_line(t_mlxp *p, t_vox a, t_vox b)
{
	t_vox	c;
	t_vox	d;

	c = vox_trunc(a);
	d = vox_trunc(b);
	printf("draw_line: <%d,%d,%d> <%d,%d,%d>\n", (int)c.x, (int)c.y, (int)c.z, (int)d.x, (int)d.y, (int)d.z);
	if (a.x == b.x)
		vertical(p, c, d);
	else if (a.y == b.y)
		horizontal(p, c, d);
	else if (fabs(b.y - a.y) < fabs(b.x - a.x))
		(a.x > b.x) ?
			gentle(p, d, c) : gentle(p, c, d);
	else
		(a.y > b.y) ?
			steep(p, d, c) : steep(p, c, d);
}
