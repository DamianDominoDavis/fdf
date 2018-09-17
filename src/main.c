/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 01:03:10 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/17 11:25:43 by cbrill           ###   ########.fr       */
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
		ft_putstr("test value: ");
		ft_putnbr(map.m[4][4]);
		ft_putendl("");
		mlx_connect_hook(&mlx);
	}
	else
		ft_putendl("usage: fdf map_path\ntry: fdf maps/test");
	return (0);
}
