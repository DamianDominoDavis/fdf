/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:32:30 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 13:32:35 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char delim)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str == delim)
			str++;
		if (*str != '\0')
			i++;
		while (*str && *str != delim)
			str++;
	}
	return (i);
}
