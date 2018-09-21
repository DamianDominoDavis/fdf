#include "fdf.h"

void	drawmap(t_mlxp *mlx, t_vmap *map)
{
	int			x;
	int			y;
	t_vox		*p;
	t_vox		*q;


	p = malloc(sizeof(t_vox));
	q = malloc(sizeof(t_vox));
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			project(p, pget(map, x, y));
			if (x + 1 < map->cols)
				drawline(mlx, *p, *project(q, pget(map, x + 1, y)));
			if (y + 1 < map->rows)
				drawline(mlx, *p, *project(q, pget(map, x, y + 1)));
			y++;
		}
		x++;
	}
	free(p);
	free(q);
}

t_vox	*pget(t_vmap *map, int x, int y)
{
	return (&map->m[y * map->cols + x]);
}

t_vox	*project(t_vox *dst, t_vox *src)
{
	double	x_cartesian = (src->x - src->z) * cos(atan(0.5));
	double	x_xwindow = X_ORI + x_cartesian;
	dst->x = x_xwindow;
	double	y_cartesian = src->y + (src->x + src->z) * sin(atan(0.5));
	double	y_xwindow = Y_ORI - y_cartesian;
	dst->y = y_xwindow;
	return (dst);
}
