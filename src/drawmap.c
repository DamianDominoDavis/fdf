#include "fdf.h"

void	drawmap(t_mlxp *mlx, t_vmap *map, t_view *v)
{
	int			x;
	int			y;
	t_xyz		p;

	x = 0;
	while (x < map->cols)
	{
		y = 0;
		while (y < map->rows)
		{
			p = project_vector(v, map, pget(map, x, y));
			if (x + 1 < map->cols)
				drawline(mlx, p, project_vector(v, map, pget(map, x, y)));
			if (y + 1 < map->rows)
				drawline(mlx, p, project_vector(v, map, pget(map, x, y)));
			y++;
		}
		x++;
	}
	//	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

t_xyz	pget(t_vmap *map, int x, int y)
{
	return (map->m[y * map->cols + x]);
}

t_xyz	project_vector(t_view *v, t_vmap *map, t_xyz p)
{
	p.x -= (double)(map->cols - 1) / 2.0f;
	p.y -= (double)(map->rows - 1) / 2.0f;
	p.z -= (double)(v->mindepth + v->maxdepth) / 2.0f;
	p = rotate(p, v);
	p.x *= v->scale;
	p.y *= v->scale;
	p.x += v->marginx;
	p.y += v->marginy;
	return (p);
}

t_xyz	rotate(t_xyz p, t_view *r)
{
	t_xyz 	tmp;
	t_xyz	out;

	tmp.x = p.x;
	tmp.z = p.z;
	out.x = cos(r->y) * tmp.x + sin(r->y) * tmp.z;
	out.z = cos(r->y) * tmp.z - sin(r->y) * tmp.x;
	tmp.y = p.y;
	tmp.z = out.z;
	out.y = cos(r->x) * tmp.y - sin(r->x) * tmp.z;
	out.z = cos(r->x) * tmp.z + sin(r->x) * tmp.y;
	out.c = p.c;
	return (out);
}
