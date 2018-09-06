/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:01:36 by cbrill            #+#    #+#             */
/*   Updated: 2018/05/03 12:07:38 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *str, void (*f)(char*))
{
	int lim;
	int i;

	if (str && str[0] && f)
	{
		i = -1;
		lim = ft_strlen(str);
		while (++i < lim)
			(*f)(&str[i]);
	}
}