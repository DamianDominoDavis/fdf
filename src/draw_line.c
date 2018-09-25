/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:42:45 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/24 18:59:07 by cbrill           ###   ########.fr       */
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
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
		if (d > 0)
		{
			a.y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		a.x += (b.x > a.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
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
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
		if (d > 0)
		{
			a.x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		a.y += (b.y > a.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
}

static void	vertical(t_mlxp *p, t_vox a, t_vox b)
{
	while (a.y != b.y)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
		a.y += (a.y < b.y) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
}

static void	horizontal(t_mlxp *p, t_vox a, t_vox b)
{
	while (a.x != b.x)
	{
		mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
		a.x += (a.x < b.x) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx, p->win, a.x, a.y, K_WHITE);
}

void		draw_line(t_mlxp *p, t_vox a, t_vox b)
{
	if (a.x == b.x)
		vertical(p, a, b);
	else if (a.y == b.y)
		horizontal(p, a, b);
	else if (fabs(b.y - a.y) < fabs(b.x - a.x))
		(a.x > b.x) ?
			gentle(p, b, a) : gentle(p, a, b);
	else
		(a.y > b.y) ?
			steep(p, b, a) : steep(p, a, b);
}
