/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 10:59:46 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/11 18:34:25 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_identifier(t_cub *cub, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R' && cub->id.r == 1)
		exit_game(cub, 13);
	if (line[i] == 'N' && line[i + 1] == 'O' && cub->id.no == 1)
		exit_game(cub, 14);
	if (line[i] == 'S' && line[i + 1] == 'O' && cub->id.so == 1)
		exit_game(cub, 15);
	if (line[i] == 'E' && line[i + 1] == 'A' && cub->id.ea == 1)
		exit_game(cub, 16);
	if (line[i] == 'W' && line[i + 1] == 'E' && cub->id.we == 1)
		exit_game(cub, 17);
	if (line[i] == 'S' && line[i + 1] == ' ' && cub->id.s == 1)
		exit_game(cub, 18);
	if (line[i] == 'F' && line[i + 1] == ' ' && cub->id.f == 1)
		exit_game(cub, 19);
	if (line[i] == 'C' && line[i + 1] == ' ' && cub->id.c == 1)
		exit_game(cub, 20);
}

void	check_file(t_cub *cub)
{
	if (cub->id.r == 0 && cub->id.no == 0 && cub->id.so == 0 && \
			cub->id.ea == 0 && cub->id.we == 0 && cub->id.s == 0 && \
			cub->id.f == 0 && cub->id.c == 0 && cub->id.m == 0)
		exit_game(cub, 8);
	if (cub->id.m == 0)
		exit_game(cub, 9);
	if (cub->id.m - cub->map.rows > 1)
		exit_game(cub, 10);
}

void	check_color(t_cub *cub, char *line, int i)
{
	int tmp;

	if (i == 1)
	{
		while (line[i])
		{
			if (ft_isalpha(line[i]))
				exit_game(cub, 26);
			i++;
		}
	}
	else
	{
		tmp = ft_atoi(&line[i]);
		if (tmp < 0 || tmp > 255)
			exit_game(cub, 27);
	}
}
