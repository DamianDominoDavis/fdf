/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:15:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/24 19:04:01 by cbrill           ###   ########.fr       */
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
	if (!(p->mlx = mlx_init()) ||
		!(p->win = mlx_new_window(p->mlx, K_W, K_H, "fdf")))
	{
		mlx_destroy(p);
		return (nope("mlx_create: mlx_init failed", -1));
	}
	p->map = map;
	return (1);
}
