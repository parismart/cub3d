/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:31:40 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/07 13:09:02 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *str;

	str = (char *)dest;
	if (src == dest)
		return (dest);
	while (n != 0)
	{
		*str = *(const char *)src;
		str++;
		src++;
		n--;
	}
	return (dest);
}
