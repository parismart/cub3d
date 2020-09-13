/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:01:37 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/03 14:25:05 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == c)
			return (char *)s + n;
		n--;
	}
	return (0);
}
