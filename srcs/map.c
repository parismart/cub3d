/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:12:47 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/11 17:46:26 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	columns_edges_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map.rows)
	{
		if (cub->map.map[i][0] != '1' && cub->map.map[i][0] != '4')
			exit_game(cub, 32);
		i++;
	}
	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
			j++;
		j--;
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != '4')
			exit_game(cub, 33);
		i++;
		j = 0;
	}
}

static void	rows_edges_map(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map.map[0][i])
	{
		if (cub->map.map[0][i] != '1' && cub->map.map[0][i] != '4')
			exit_game(cub, 30);
		i++;
	}
	i = 0;
	while (i < cub->map.columns)
	{
		if (cub->map.map[cub->map.rows - 1][i] != '1' \
				&& cub->map.map[cub->map.rows - 1][i] != '4' && \
				cub->map.map[cub->map.rows - 1][i] != '\0')
			exit_game(cub, 31);
		i++;
	}
}

static void	edges_map(t_cub *cub)
{
	int i;
	int j;

	i = 1;
	while (i < cub->map.rows - 1)
	{
		j = 1;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '4' && ((j != 0 && cub->map.map[i]\
					[j - 1] == '0') || (j != cub->map.columns - 1 && \
					cub->map.map[i][j + 1] == '0') || cub->map.map[i - 1][j] \
					== '0' || cub->map.map[i + 1][j] == '0'))
				exit_game(cub, 29);
			j++;
		}
		i++;
	}
}

static void	position_map(t_cub *cub, int i, int j)
{
	if (ft_isalpha(cub->map.map[i][j]) && cub->map.map[i][j] != 'N' && \
			cub->map.map[i][j] != 'S' && cub->map.map[i][j] != 'E' && \
			cub->map.map[i][j] != 'W')
		exit_game(cub, 11);
	if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W')\
			&& cub->id.player == 0)
	{
		cub->rc.pos_x = j + 0.5;
		cub->rc.pos_y = i + 0.5;
		cub->map.orientation = cub->map.map[i][j];
		cub->id.player = 1;
	}
	else if ((cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' \
			|| cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W')\
			&& cub->id.player == 1)
		exit_game(cub, 21);
}

void		check_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < cub->map.rows)
	{
		while (cub->map.map[i][j])
		{
			position_map(cub, i, j);
			if (cub->map.map[i][j] == '2')
				cub->rc.nbr_sprites += 1;
			j++;
		}
		i++;
		j = 0;
	}
	if (cub->id.player == 0)
		exit_game(cub, 22);
	edges_map(cub);
	rows_edges_map(cub);
	columns_edges_map(cub);
}
