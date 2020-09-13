/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:48:37 by parmarti          #+#    #+#             */
/*   Updated: 2020/07/08 19:28:57 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rows(char const *s, char c)
{
	int rows;

	rows = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (rows);
		while (*s && *s != c)
			s++;
		rows++;
	}
	return (rows);
}

static int	ft_columns(char const *s, char c)
{
	int	columns;

	columns = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		columns++;
		s++;
	}
	return (columns);
}

static char	**ft_free(char **str, int i)
{
	while (i)
		free(str[i--]);
	free(str);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		rows;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	rows = ft_rows(s, c);
	if (!(str = (char **)malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	i = 0;
	while (i < rows)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * ft_columns(s, c) + 1)))
			return (ft_free(str, i));
		while (*s == c)
			s++;
		j = 0;
		while (*s && *s != c)
			str[i][j++] = *s++;
		str[i][j] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
