/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:03:10 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/21 16:46:25 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nope(char *str, int rval)
{
	ft_putendl(str);
	return (rval);
}

int		main(int c, char **v)
{
	t_mlxp	mlx;
	t_vmap	map;
	//t_view	view;

	if (c == 2)
	{
		ft_putendl("main: start");
		if (!(map_load(&map, v[1])))
			return nope("main: could not load map", -1);
		ft_putendl("main: map loaded");
		if (!(mlx_create(&mlx, &map)))
		{
			mlx_destroy(&mlx);
			return nope("main.c:main\tcould not create mlx", -1);
		}
		ft_putendl("main: mlx created");
		//mlx_clear_window(mlx->mlx, mlx->win);
		map.scale = 0.9 * fmin(K_W, K_H) / (2 + fmax(map.rows, map.cols));
		draw_map(&mlx, &map);
		fdf_connect_hook(&mlx);
	}
	else
		ft_putendl("usage: fdf map_path\ntry: fdf maps/test");
	return (0);
}
