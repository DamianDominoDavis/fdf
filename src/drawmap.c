#include "fdf.h"

void	drawmap(t_mlxp *mlx, t_vmap *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
			if (map->m[y][x])
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, mlx->color);
	}
}
