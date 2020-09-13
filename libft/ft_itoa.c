/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 09:16:27 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/07 12:09:23 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			l;
	long long	nbr;

	l = ft_nbrlen(n);
	if (!(str = malloc(sizeof(char) * l + 1)))
		return (0);
	str[l--] = '\0';
	if (n == 0)
		str[0] = 48;
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[l--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
