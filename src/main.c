/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:03:10 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/28 12:22:17 by cbrill           ###   ########.fr       */
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

	if (c == 2)
	{
		if (0 > (map_create(&map, v[1])))
			return (nope("main: could not load map", -1));
		if (0 > (mlx_create(&mlx, &map)))
		{
			mlx_destroy(&mlx);
			return (nope("main.c:main\tcould not create mlx", -1));
		}
		draw_map(&mlx, &map);
		fdf_connect_hook(&mlx);
	}
	else
		ft_putendl("usage: fdf map_path\ntry: fdf maps/42.fdf");
	return (0);
}
