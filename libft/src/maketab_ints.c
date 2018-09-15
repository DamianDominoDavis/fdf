/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maketab_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:01:57 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/14 17:40:15 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** maketab_ints returns a wrapper for a (map) double pointer of ints (r) rows long and (c) columns in size, NOT null-terminated.
**
** Failure to allocate enough space returns NULL.
*/

t_tab2dint	*maketab_ints(t_tab2dint *tab, unsigned int r, unsigned int c)
{
	unsigned int i;

	if (!(tab->map = (int **)malloc(sizeof(int *) * r)))
		return (NULL);
	tab->map[0] = NULL;
	if (!(tab->map[0] = (int *)malloc(sizeof(int) * c * r)))
		return (NULL);
	else
	{
		i = -1;
		while (++i < r)
			tab->map[i] = (*tab->map + c * i);
		tab->r = r;
		tab->c = c;
	}
	return (tab);
}
