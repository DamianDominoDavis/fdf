/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:42:45 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/11 01:30:01 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawlinelo(int c[], t_mlxp *p)
{
	int dx;
	int dy;
	int yi;
	int d;

	dx = c[2] - c[0];
	dy = (c[3] - c[1] > 0) ? (c[3] - c[1]) : (c[1] - c[3]);
	yi = (c[3] - c[1] > 0) ? 1 : -1;
	d = 2 * dy - dx;
	while (c[0] != c[2])
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
		if (d > 0)
		{
			c[1] += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		c[0] += (c[2] > c[0]) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
}

void	drawlinehi(int c[], t_mlxp *p)
{
	int dx;
	int dy;
	int xi;
	int d;

	dx = (c[2] - c[0] > 0) ? (c[2] - c[0]) : (c[0] - c[2]);
	dy = c[3] - c[1];
	xi = (c[2] - c[0] > 0) ? 1 : -1;
	d = 2 * dx - dy;
	while (c[1] != c[3])
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
		if (d > 0)
		{
			c[0] += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		c[1] += (c[3] > c[1]) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
}

void	drawlinevl(int c[], t_mlxp *p)
{
	while (c[1] != c[3])
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
		c[1] += (c[1] < c[3]) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
}

void	drawlinehl(int c[], t_mlxp *p)
{
	while (c[0] != c[2])
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
		c[0] += (c[0] < c[2]) ? 1 : -1;
	}
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, c[0], c[1], p->color);
}

void	drawline(int c[], t_mlxp *p)
{
	if (c[0] == c[2])
		drawlinevl(c, p);
	else if (c[1] == c[3])
		drawlinehl(c, p);
	else if (abs(c[3] - c[1]) < abs(c[2] - c[0]))
		(c[0] > c[2]) ?
			drawlinelo((int[]){c[2], c[3], c[0], c[1]}, p) : drawlinelo(c, p);
	else
		(c[1] > c[3]) ?
			drawlinehi((int[]){c[2], c[3], c[0], c[1]}, p) : drawlinehi(c, p);
}
