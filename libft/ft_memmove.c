/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:08:17 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/01 13:59:29 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *temp;

	temp = (char *)dest;
	if (dest > src)
	{
		while (n != 0)
		{
			n--;
			temp[n] = ((char *)src)[n];
		}
	}
	else
		ft_memcpy(temp, src, n);
	return (dest);
}
