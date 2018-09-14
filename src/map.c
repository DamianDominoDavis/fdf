/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiandavis <damiandavis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/14 14:47:04 by damiandavis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** files are space-separated signed int values, in any number of lines and
** the same number of values per line
**
** setbuffwidth is pointless for gnl, but it could be libft src in future
*/

int	*getsize(int fd)
{
	char *line;
	char **split;
	const int width;
	int height;

	line = NULL;
	height = 1;
	(1 == get_next_line(fd, line)) ?
		width = ft_wordcount(line) : return ((int[]){0,0});
	while (1 == get_next_line(fd, line))
	{
		if (width != ft_wordcount())
			return ((int[]){0,0});
		hwight++;
	}
	return ((int[]){width,height});
}

/*
** free splits values, splits before return
*/

int	**linetoints(char *str)
{
	char	**splits;
	int		**out;
	int		i;
	int		wc;

	splits = ft_strsplit(str, ' ');
	wc = ft_wordcount(str, ' ');
	out = (int**)malloc(sizeof(int*) * (wc + 1));
	out[wc] = NULL;
	ft_putendl("map.linetoints");
	i = 0;
	while (i < wc && *(splits[i]))
	{
		ft_putstr("  string:\"");
		ft_putstr(splits[i]);
		ft_putstr("\" int:");
		ft_putnbr(ft_atoi(splits[i]));
		ft_putendl("");
		// *out[i] = ft_atoi(splits[i]);
		i++;
	}
	ft_putendl("endline");
	return (out);
}

int	**mapfromfile(int fd, t_mlxp *p)
{
	int	*size;
	void	*ptr;

	if (0 == (size = getsize(fd)))
		return nope("map.c:mapfromfile - file format error", 0);
	p->width = size[0];
	p->height = size[1];
	p->map = (int**)malloc(sizeof(int*) * (p->height + 1));
	ft_memset(p->map, 0, sizeof(p->map));
	ptr = *map;
	while (*ptr)
		;
}
