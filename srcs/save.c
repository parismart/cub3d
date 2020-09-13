/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:13:26 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/11 18:38:20 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	alloc_map(t_cub *cub)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map.tmp[i])
	{
		if (cub->map.tmp[i] == '\n')
		{
			if (cub->map.columns < j)
				cub->map.columns = j - 1;
			j = 0;
		}
		i++;
		j++;
	}
	if (!(cub->map.map = malloc(sizeof(char*) * (cub->map.rows + 1))))
		exit_game(cub, 6);
	i = 0;
	while (i < cub->map.rows)
	{
		if (!(cub->map.map[i++] = ft_calloc(sizeof(char), \
		(cub->map.columns + 1))))
			exit_game(cub, 6);
	}
}

void		save_map(t_cub *cub)
{
	int i;
	int	j;
	int	k;

	i = 0;
	while (cub->map.tmp[i++])
	{
		if (cub->map.tmp[i] == ' ')
			cub->map.tmp[i] = '4';
	}
	alloc_map(cub);
	i = 0;
	j = 0;
	k = 0;
	while (cub->map.tmp[k++])
	{
		if (cub->map.tmp[k] != '\n')
			cub->map.map[i][j++] = cub->map.tmp[k];
		else
		{
			cub->map.map[i++][j] = '\0';
			j = 0;
		}
	}
	cub->map.map[cub->map.rows] = NULL;
}

int			save_color(t_cub *cub, char *line, int i)
{
	int color;

	i++;
	check_color(cub, line, i);
	while (ft_isspace(line[i]))
		i++;
	check_color(cub, line, i);
	color = ft_atoi(&line[i]) * pow(2, 16);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ',')
		exit_game(cub, 28);
	while (line[i] == ',' || line[i] == ' ')
		i++;
	check_color(cub, line, i);
	color += ft_atoi(&line[i]) * pow(2, 8);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != ',')
		exit_game(cub, 28);
	while (line[i] == ',' || line[i] == ' ')
		i++;
	check_color(cub, line, i);
	color += ft_atoi(&line[i]);
	return (color);
}

char		*save_texture(char *line, int i)
{
	char	*texture;

	while (ft_isalpha(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	texture = ft_strdup(&line[i]);
	return (texture);
}

void		save_res(t_cub *cub, char *line, int i)
{
	int tmp;

	cub->id.r = 1;
	i++;
	while (ft_isspace(line[i]))
		i++;
	tmp = i;
	while (line[tmp])
	{
		if (ft_isalpha(line[tmp]))
			exit_game(cub, 23);
		tmp++;
	}
	if (ft_isdigit(line[i]))
		cub->map.width = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		cub->map.height = ft_atoi(&line[i]);
}
