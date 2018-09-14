/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 17:54:21 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** files are space-separated signed int values, in any number of lines and
** the same number of values per line
**
** setbuffwidth is pointless for gnl, but it could be libft src in future
*/

int	setbuffwidth(int fd)
{
	char	**buf;
	size_t	llen;
	size_t	record;

	record = 0;
	buf = (char**)malloc(sizeof(char*));
	llen = 0;
	while (0 < (get_next_line(fd, buf)))
	{
		if (llen < ft_strlen(*buf))
			llen = ft_strlen(*buf);
		ft_putnbr(llen);
		ft_putendl("");
		if (llen > record)
			record = llen;
	}
	ft_strdel(buf);
	ft_memdel((void**)buf);
	return (record);
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

int	**mapfromfile(int fd)
{
	char	**line;

	line = (char**)malloc(sizeof(char*));
	if (0 <= get_next_line(fd, line))
		return (linetoints(*line));
	return (NULL);
}
