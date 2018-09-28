/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:16:15 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/28 12:16:19 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_allot(t_vmap *map)
{
	int	i;

	i = -1;
	if (!(map->m = (t_vox*)malloc(sizeof(t_vox) * map->rows * map->cols)))
		return (nope("map_allot: can't malloc *t_vox", -1));
	return (1);
}

static int	map_size(t_vmap *map, char *path)
{
	char	*line;
	int		fd;

	if (0 > (fd = open(path, O_RDONLY)))
		return (nope("map_size: can't open file", -1));
	line = NULL;
	if (1 != get_next_line(fd, &line))
		return (nope("map_size: can't read file (empty?)", -1));
	map->cols = ft_wordcount(line, ' ');
	map->rows = 1;
	while (1 == get_next_line(fd, &line))
	{
		if (map->cols != (int)ft_wordcount(line, ' '))
			return (nope("map_size: file format error", -1));
		map->rows++;
	}
	map->scale = K_SCALE;
	map->tile = 0.8 * fmin(K_W, K_H) / (sqrt(2) * fmax(map->rows, map->cols));
	return (map->rows);
}

static void	splint(t_vmap *map, int row, char **strs)
{
	int		i;
	t_vox	*v;

	i = -1;
	while (++i < map->cols)
	{
		v = &map->m[map->cols * row + i];
		v->x = i;
		v->y = row;
		v->z = ft_atoib(strs[i], 10) * 10;
		if (ft_strchr(strs[i], ','))
			v->c = ft_atoib(ft_strchr(strs[i], 'x') + 1, 16);
		else
			v->c = K_WHITE;
	}
}

int			map_create(t_vmap *map, char *path)
{
	int		fd;
	char	*line;
	int		i;

	ft_putendl("map_create: start");
	if (0 >= map_size(map, path))
		return (nope("map_create: bad map size", -1));
	ft_putendl("map_create: map_size ok");
	if (0 > map_allot(map))
		return (nope("map_create: map_allot failed", -1));
	ft_putendl("map_create: map_allot ok");
	if (0 > (fd = open(path, O_RDONLY)))
		return (nope("map_create: can't open file", -1));
	ft_putendl("map_create: file open ok");
	i = -1;
	while (++i < map->rows)
	{
		get_next_line(fd, &line);
		splint(map, i, ft_strsplit(line, ' '));
	}
	ft_putendl("map_create: lines read");
	return (1);
}

void		map_destroy(t_vmap *map)
{
	if (map && map->m)
	{
		free(map->m);
	}
}
