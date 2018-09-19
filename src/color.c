/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damiandavis <damiandavis@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 20:57:57 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/12 15:34:19 by damiandavis      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	intcolor(int r, int g, int b)
{
	if (r > 255 || g > 255 | b > 255 || r < 0 || g < 0 || b < 0)
		return (-1);
	return ((int)(256 * 256 * r + 256 * g + b));
}

int	colorasdepth(int c)
{
	return (int)((double)(c) / 10.0f * (double)intcolor(255,255,255));
}