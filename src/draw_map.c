/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:02:00 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/27 17:07:10 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vox	vox_get(t_vmap *map, int x, int y)
{
	t_vox o;

	o = map->m[y * map->cols + x];
	o.x = (int)o.x;
	o.y = (int)o.y;
	o.z = (int)o.z;
	return (o);
}

static void		do_offset(t_vmap *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			map->m[i * map->cols + j].x -= (map->rows / 2);
			map->m[i * map->cols + j].y -= (map->cols / 2);
			map->m[i * map->cols + j].x *= ((K_H / map->rows) * map->tile);
			map->m[i * map->cols + j].y *= ((K_W / map->cols) * map->tile);
			map->m[i * map->cols + j].x = (map->m[i * map->cols + j].x
				- map->m[i * map->cols + j].y) / (K_W / map->cols);
			map->m[i * map->cols + j].y = (map->m[i * map->cols + j].x
				- map->m[i * map->cols + j].y) / (-1 * K_H / map->rows);
			map->m[i * map->cols + j].z *= map->scale;
			map->m[i * map->cols + j].y -= map->m[i * map->cols + j].z;
			map->m[i * map->cols + j].x += (K_H / 2);
			map->m[i * map->cols + j].y += (K_W / 2);
		}
	}
}

void			draw_map(t_mlxp *mlx, t_vmap *map)
{
	int			x;
	int			y;

	do_offset(map);
	x = -1;
	while (++x < map->cols)
	{
		y = -1;
		while (++y < map->rows)
		{
			if (x + 1 < map->cols)
				draw_line(mlx, vox_get(map, x, y), vox_get(map, x + 1, y));
			if (y + 1 < map->rows)
				draw_line(mlx, vox_get(map, x, y), vox_get(map, x, y + 1));
		}
	}
}

int				gradient(int start, int end, int steps)
{
	int rgb[3];

	if (steps == 0)
		return (end);
	if (steps < 0)
		steps *= -1;
	rgb[0] = (start & 0xFF0000) >> 16;
	rgb[0] += (rgb[0] - ((end & 0xFF0000) >> 16)) / steps;
	rgb[1] = (start & 0x00FF00) >> 8;
	rgb[1] += (rgb[1] - ((end & 0x00FF00) >> 8)) / steps;
	rgb[2] = (start & 0x0000FF);
	rgb[2] += (rgb[2] - ((end & 0x0000FF))) / steps;
	return (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
}
