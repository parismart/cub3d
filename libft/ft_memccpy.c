/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:55:26 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/07 12:10:32 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n != 0)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dest);
		src++;
		n--;
	}
	return (0);
}
