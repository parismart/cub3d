/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 10:27:12 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/08 19:23:41 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_checkset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_checkset(s1[end - 1], set))
		end--;
	if (end < start)
		str = ft_strdup("");
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
			return (NULL);
		i = 0;
		while (start < end)
			str[i++] = s1[start++];
		str[i] = 0;
	}
	return (str);
}
