/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:57:38 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/12 19:43:58 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	str_become(char **dst, const char *src)
{
	ft_strdel(dst);
	*dst = (char*)src;
}

static int	get_next_loop(const int fd, char **fds, char *buf)
{
	int	rch;

	rch = 1;
	while (0 < (rch = read(fd, buf, BUFF_SIZE)))
	{
		buf[rch] = '\0';
		str_become(&fds[fd], ft_strjoin(fds[fd], buf));
		if (!fds[fd])
			fds[fd] = ft_strdup(buf);
	}
	return (rch);
}

int		get_next_line(const int fd, char **line)
{
	int			rch;
	char		buf[BUFF_SIZE + 1];
	static char	*fds[5000];
	char		*tmp;

	if (fd < 0 || !line)
		return (-1);
	while (0 < (rch = get_next_loop(fd, fds, buf)))
		;
	if ((rch == -1 || !ft_strlen(fds[fd])))
	{
		if (!line)
			*line = ft_strnew(0);
		return (rch);
	}
	tmp = ft_strchr(fds[fd], '\n');
	if (tmp && !(*tmp = '\0'))
		tmp = ft_strdup(tmp + 1);
	else
		tmp = ft_strnew(0);
	*line = ft_strdup(fds[fd]);
	str_become(&fds[fd], tmp);
	return (1);
}
