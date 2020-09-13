/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:34:57 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/08 17:38:54 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t n;
	size_t i;

	d = ft_strlen(dst);
	n = ft_strlen(src);
	n = n + d;
	if (size < d)
	{
		n = n + size - d;
		return (n);
	}
	i = 0;
	while (src[i] && size > 0 && (d + 1) < size)
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (n);
}
