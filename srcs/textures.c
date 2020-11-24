/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:17:31 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/13 17:55:58 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	choose_texture(t_cub *cub)
{
	if (cub->rc.side == 0 && cub->rc.raydir_x > 0)
		return (cub->east);
	else if (cub->rc.side == 0 && cub->rc.raydir_x < 0)
		return (cub->west);
	else if (cub->rc.side == 1 && cub->rc.raydir_y > 0)
		return (cub->south);
	else
		return (cub->north);
}

void				draw_texture(t_cub *cub, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_texture	tex_wall;

	tex_wall = choose_texture(cub);
	if (cub->rc.side == 0)
		wall_x = cub->rc.pos_y + cub->rc.perp_wall_dist * cub->rc.raydir_y;
	else
		wall_x = cub->rc.pos_x + cub->rc.perp_wall_dist * cub->rc.raydir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)tex_wall.width;
	y = cub->rc.draw_start;
	while (y++ < cub->rc.draw_end)
	{
		tex_y = (y - cub->map.height / 2 + cub->rc.line_height / 2) \
		* tex_wall.height / cub->rc.line_height;
		if (tex_y < 0)
			return ;
		cub->get_data[x + y * cub->map.width] = \
		tex_wall.get_data[tex_x + tex_y * tex_wall.width];
	}
}

static void			coord_sprites(t_cub *cub)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < cub->map.rows)
	{
		x = 0;
		while (x < cub->map.columns)
		{
			if (cub->map.map[y][x] == '2')
			{
				cub->sprite[i].coord_x = x + 0.5;
				cub->sprite[i].coord_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static t_texture	set_texture(char *root_texture, t_cub *cub)
{
	t_texture	texture;

	if (!(texture.img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, root_texture, \
	&texture.width, &texture.height)))
		exit_game(cub, 24);
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.img_ptr, \
	&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
		exit_game(cub, 24);
	return (texture);
}

void				init_textures(t_cub *cub)
{
	int	i;

	cub->north = set_texture(cub->map.north, cub);
	cub->south = set_texture(cub->map.south, cub);
	cub->east = set_texture(cub->map.east, cub);
	cub->west = set_texture(cub->map.west, cub);
	if (!(cub->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite), \
	cub->rc.nbr_sprites)))
		exit_game(cub, 6);
	i = -1;
	while (++i < cub->rc.nbr_sprites)
	{
		if (!(cub->sprite[i].img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, \
		cub->map.sprite, &cub->sprite[i].width, &cub->sprite[i].height)))
			exit_game(cub, 25);
		if (!(cub->sprite[i].get_data = \
		(int *)mlx_get_data_addr(cub->sprite[i].img_ptr, \
		&cub->sprite[i].bits_per_pixel, &cub->sprite[i].size_line, \
		&cub->sprite[i].endian)))
			exit_game(cub, 25);
	}
	coord_sprites(cub);
}
