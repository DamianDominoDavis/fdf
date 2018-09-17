/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/15 18:35:07 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** files are space-separated signed int values, in any number of lines and
** the same number of values per line
*/

void	getsize(char *path, t_mlxp *p)
{
	char **line;
	int fd;

	fd = open(path, O_RDONLY);
	line = (char**)malloc(sizeof(char*));
	
	if (1 == get_next_line(fd, line))
	{
		p->map.c = ft_wordcount(*line, ' ');
		while (1 == get_next_line(fd, line))
		{
			if (p->map.c != ft_wordcount(*line, ' '))
				return ;
			p->map.r++;
		}
	}
	else
	{
		p->map.c = 0;
		p->map.r = 0;
	}
}

/*
** free splits values, splits before return
*/

static void	linetoints(char *str, const int c, int *mline)
{
	char	**split;
	char	*ptr;
	int		i;
	
	split = ft_strsplit(str, ' ');
	ptr = *split;
	i = 0;
	while (i < c)
	{
		if (*ptr)
			mline[i] = ft_atoi(ptr);
		ptr = split[++i];
	}
}

void		mapfromfile(char *path, t_mlxp *p)
{
	unsigned int	i;
	char			**line;
	int				fd;
	
	getsize(path, p);
	if (p->map.c == 0)
		return ;
	maketab_ints(&(p->map), p->map.r, p->map.c);
	fd = open(path, O_RDONLY);
	i = 0;
	line = (char**)malloc(sizeof(char*));
	while (i < p->map.r)
	{
		get_next_line(fd, line);
		linetoints(*line, p->map.c, p->map.map[i++]);
	}
}
