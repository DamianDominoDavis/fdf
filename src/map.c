/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:16:15 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/16 16:35:12 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_allot(t_vmap *map)
{
	int i;

	i = -1;
	if (!(map->m = (int **)malloc(sizeof(int *) * map->rows)))
		return nope("map_allot: can't malloc map head", -1);
	map->m[0] = NULL;
	if (!(map->m[0] = (int *)malloc(sizeof(int) * map->cols * map->rows)))
		return nope("map_allot: can't malloc map rows", -1);
	else
		while (++i < map->rows)
			map->m[i] = (*(map->m) + map->cols * i);
	return (1);
}

static int	map_size(t_vmap *map, char *path)
{
	char *line;
	int fd;
	int r;

	if (0 > (fd = open(path, O_RDONLY)))
		return nope("map_size: can't open file", -1);
	line = NULL;
	if (1 != (r = get_next_line(fd, &line)))
		return nope("map_size: can't read file (empty?)", -1);
	map->cols = ft_wordcount(line, ' ');
	map->rows = 1;
	while (1 == get_next_line(fd, &line))
	{
		if (map->cols != (int)ft_wordcount(line, ' '))
			return nope("map_size: file format error", -1);
		map->rows++;
	}
	return (map->rows);
}

static void	splint(int c, char **strs, int *dst)
{
	int i;

	i = -1;
	while (++i < c)
		dst[i] = ft_atoi(strs[i]);
}

int	map_load(t_vmap *map, char *path)
{
	int				fd;
	char			*line;
	int	i;
	
	ft_putendl("map_load: start");
	if (0 >= map_size(map, path))
		return nope("map_load: bad map size", -1);
	ft_putendl("map_load: map_size ok");
	if (0 > map_allot(map))
		return nope("map_load: map_allot failed", -1);
	ft_putendl("map_load: map_allot ok");
	if (0 > (fd = open(path, O_RDONLY)))
		return nope("map_load: can't open file", -1);
	ft_putendl("map_load: file open ok");
	i = -1;
	while (++i < map->rows)
	{
		get_next_line(fd, &line);
		splint(map->cols, ft_strsplit(line, ' '), map->m[i]);
	} 
	ft_putendl("map_load: lines read");
	return (1);
}

void	map_destroy(t_vmap *map)
{
	int i;

	if (map && map->m)
	{
		i = -1;
		while (++i < map->rows)
			free(map->m[i]);
		free(map->m);
	}
}
