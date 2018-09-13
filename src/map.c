/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:46:18 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/12 19:58:16 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate(char *file)
{
	int ok = 1;
	int fd;
	if (!(fd = open(file, O_RDONLY)))
		nope("map.validate: could not open", -1);
	while
}
 
 /*

files are whitespace-separated signed int values, in any number of lines and
the same number of values per line

 */
