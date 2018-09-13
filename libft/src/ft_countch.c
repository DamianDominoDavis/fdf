/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:35:51 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 13:37:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countch(const char *str, const unsigned char ch)
{
	char	*s;
	int		i;

	s = (char*)str;
	i = 0;
	while (*s)
		if (*s++ == ch)
			i++;
	return (i);
}
