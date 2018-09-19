/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:15:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/17 11:44:06 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_destroy(t_mlxp *p)
{
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->map)
		map_destroy(p->map);
	exit(0);
}

int		mlx_create(t_mlxp *p, t_vmap *map)
{
	// if (!(p = ft_memalloc(sizeof(t_mlxp))))
	// 	return nope("mlx_create: can't allocate mlxp", -1);
	(void)map;
	p->color = intcolor(255, 255, 255);
	if (!(p->mlx = mlx_init()) ||
		!(p->win = mlx_new_window(p->mlx, K_W, K_H, "fdf")))
	{
		mlx_destroy(p);
		return nope("mlx_create: mlx_init failed", -1);
	}
	return (1);
}

int		view_create(t_view *v)
{
	v->mindepth = 0;
	v->maxdepth = 0;
	v->scale = 0;
	v->x = 0;
	v->y = 0;
	v->marginx = 0;
	v->marginy = 0;
	return (1);
}
