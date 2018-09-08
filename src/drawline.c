/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 18:56:57 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/07 19:21:53 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	k[5] = dx, dy, p, x, y
*/

void	drawline(int x0, int y0, int x1, int y1)
{
	int	k[5];

	k[0] = x1 - x0;
	k[1] = y1 - y0;
	k[3] = x0 - 1;
	k[4] = y0;
	k[2] = 2 * k[1] - k[0];
	while (++k[3] < x1)
	{
		if (k[2] >= 0)
		{
			putpixel(k[3], k[4]);
			k[4] += 1;
			k[2] += 2 * k[1] - 2 * k[0];
		}
		else
		{
			putpixel(k[3], k[4]);
			k[2] += 2 * k[1];
		}
	}
}
