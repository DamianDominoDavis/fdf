/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 16:08:06 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** files are tab-separated signed int values, in any number of lines and
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
	int		**out;
	int		*o;
	char	**splits;
	int		count;

	count = ft_wordcount(str, '\t');
	out = (int**)malloc(sizeof(int*) * count);
	splits = ft_strsplit(str, '\t');
	o = *out;
	while (count--)
	{
		*(o++) = ft_atoi(*(splits++));
	}
	return (out);
}

int	**mapfromfile(int fd)
{
	(void)fd;
	return (NULL);
}
