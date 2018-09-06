/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:27:28 by cbrill            #+#    #+#             */
/*   Updated: 2018/04/21 16:58:03 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strdel(char **str)
{
	if (!str)
		return ;
	ft_memdel((void**)str);
	*str = NULL;
}
