/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:24:12 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/13 14:20:12 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	color_sprite(t_cub *cub, int i)
{
	if (cub->rs.tex_y > 0)
	{
		if (cub->sprite[i].get_data[cub->rs.tex_x + cub->rs.tex_y * \
		cub->sprite[i].width] != 0)
			cub->sprite[i].color = cub->sprite[i].get_data\
			[cub->rs.tex_x + cub->rs.tex_y * cub->sprite[i].width];
		else
			cub->sprite[i].color = 0xBFD195;
	}
}

static void	draw_sprite(t_cub *cub, int x, int i)
{
	int	y;
	int	d;

	y = cub->rs.draw_start_y;
	while (y < cub->rs.draw_end_y)
	{
		d = (y * 256 - cub->map.height * 128 + cub->rs.height * 128);
		cub->rs.tex_y = (d * cub->sprite[i].height / cub->rs.height) / 256;
		color_sprite(cub, i);
		if (cub->sprite[i].color != 0xBFD195 && \
				cub->rs.transform_y < cub->rs.dist_wall[x])
		{
			if (x >= 0 && x < cub->map.width && y >= 0 && y < cub->map.height)
			{
				cub->get_data[x + y * (cub->size_line / 4)] = \
					cub->sprite[i].color;
			}
		}
		y++;
	}
}

static void	init_raysprite(t_cub *cub, int i)
{
	cub->rs.x = cub->sprite[cub->sprite[i].order].coord_x - cub->rc.pos_x;
	cub->rs.y = cub->sprite[cub->sprite[i].order].coord_y - cub->rc.pos_y;
	cub->rs.inv_det = 1 / (cub->rc.plan_x * cub->rc.dir_y \
			- cub->rc.dir_x * cub->rc.plan_y);
	cub->rs.transform_x = cub->rs.inv_det * \
			(cub->rc.dir_y * cub->rs.x - cub->rc.dir_x * cub->rs.y);
	cub->rs.transform_y = cub->rs.inv_det * \
			(-cub->rc.plan_y * cub->rs.x + cub->rc.plan_x * cub->rs.y);
	cub->rs.screen_x = (int)((cub->map.width / 2) * \
			(1 + cub->rs.transform_x / cub->rs.transform_y));
	cub->rs.height = abs((int)(cub->map.height / cub->rs.transform_y));
	cub->rs.draw_start_y = cub->map.height / 2 - cub->rs.height / 2;
	if (cub->rs.draw_start_y < 0)
		cub->rs.draw_start_y = 0;
	cub->rs.draw_end_y = cub->map.height / 2 + cub->rs.height / 2;
	if (cub->rs.draw_end_y >= cub->map.height)
		cub->rs.draw_end_y = cub->map.height - 1;
	cub->rs.width = abs((int)(cub->map.height / cub->rs.transform_y));
	cub->rs.draw_start_x = cub->rs.screen_x - cub->rs.width / 2;
	if (cub->rs.draw_start_x < 0)
		cub->rs.draw_start_x = 0;
	cub->rs.draw_end_x = cub->rs.screen_x + cub->rs.width / 2;
	if (cub->rs.draw_end_x >= cub->map.width)
		cub->rs.draw_end_x = cub->map.width - 1;
}

static void	sort_sprite(t_cub *cub)
{
	int	i;
	int	swap;

	i = 0;
	while (i + 1 < cub->rc.nbr_sprites)
	{
		if (cub->sprite[i].distance < \
		cub->sprite[cub->sprite[i + 1].order].distance)
		{
			swap = cub->sprite[i].order;
			cub->sprite[i].order = cub->sprite[i + 1].order;
			cub->sprite[i + 1].order = swap;
			sort_sprite(cub);
		}
		i++;
	}
}

void		raysprite(t_cub *cub)
{
	int	i;
	int	x;

	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		cub->sprite[i].order = i;
		cub->sprite[i].distance = pow(cub->rc.pos_x - \
		cub->sprite[i].coord_x, 2) + pow(cub->rc.pos_y - \
		cub->sprite[i].coord_y, 2);
	}
	sort_sprite(cub);
	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		init_raysprite(cub, i);
		x = cub->rs.draw_start_x - 1;
		while (++x < cub->rs.draw_end_x && x < cub->map.width)
		{
			cub->rs.tex_x = (int)(256 * (x - (-cub->rs.width / 2 + \
			cub->rs.screen_x)) * cub->sprite[i].width / cub->rs.width) / 256;
			if (cub->rs.transform_y > 0)
				draw_sprite(cub, x, i);
		}
	}
}
