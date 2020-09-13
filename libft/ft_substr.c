/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 19:25:01 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/08 19:18:31 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	strlen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	strlen = slen - start;
	if (strlen < len)
		len = strlen;
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
