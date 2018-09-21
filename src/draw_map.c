#include "fdf.h"

void	draw_map(t_mlxp *mlx, t_vmap *map)
{
	int			x;
	int			y;
	t_vox		*p;
	t_vox		*q;


	p = malloc(sizeof(t_vox));
	q = malloc(sizeof(t_vox));
	x = 0;
	while (x < map->cols)
	{
		y = 0;
		while (y < map->rows)
		{
			vox_proj(map, p, vox_get(map, x, y));
			if (x + 1 < map->cols)
				draw_line(mlx, *p, *vox_proj(map, q, vox_get(map, x + 1, y)));
			if (y + 1 < map->rows)
				draw_line(mlx, *p, *vox_proj(map, q, vox_get(map, x, y + 1)));
			y++;
		}
		x++;
	}
	free(p);
	free(q);
}

t_vox	*vox_get(t_vmap *map, int x, int y)
{
	return (&map->m[y * map->cols + x]);
}

t_vox	*vox_proj(t_vmap *map, t_vox *dst, t_vox *src)
{
	(void)map;
	double	x_cartesian = (src->x - src->z) * cos(atan(0.5));
	double	x_xwindow = X_ORI + map->scale * x_cartesian;
	dst->x = x_xwindow;
	double	y_cartesian = src->y + (src->x + src->z) * sin(atan(0.5));
	double	y_xwindow = Y_ORI - map->scale * y_cartesian;
	dst->y = y_xwindow;
	return (dst);
}

t_vox	vox_trunc(t_vox p)
{
	t_vox i;

	i.x = (int)p.x;
	i.y = (int)p.y;
	i.z = (int)p.z;
	i.c = p.c;
	return i;
}
