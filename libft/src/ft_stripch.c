/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stripch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:41:36 by cbrill            #+#    #+#             */
/*   Updated: 2018/09/13 13:41:41 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char    *ft_stripch(const char *str, unsigned int n, const unsigned char ch)
// {
// 	char    *out;
// 	char    *o;
// 	char    *s;

// 	if (!str)
// 		return (NULL);
// 	if (n == 0 || ft_countch(str, ch) == 0)
// 		return (ft_strdup(str));
// 	if (!(out = ft_strnew(ft_strlen(str) - ft_countch(str, ch))))
// 		return (NULL);
// 	o = out;
// 	s = (char*)str--;
// 	while (n--)
// 		if (*(++s) != ch)
// 			*o++ = *s;
// 	*o = '\0';
// 	return (out);
// }

char	*ft_stripch(const char *str, unsigned int n, const unsigned char ch)
{
	char	*out;
	char	*o;
	char	*s;

	if (!str)
		return (NULL);
	if (n == 0 || ft_countch(str, ch) == 0)
		return (ft_strdup(str));
	s = (char*)str;
	out = ft_strnew(ft_strlen(str) - ft_countch(str, ch));
	o = out;
	if (!o)
		return (NULL);
	while (n--)
		if (*s == ch)
			s++;
		else
			*o++ = *s++;
	*o = '\0';
	return (out);
}
