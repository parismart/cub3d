/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:41:41 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/11 18:28:14 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_frame(t_cub *cub)
{
	if (!(cub->new_image = mlx_new_image(cub->mlx_ptr, cub->map.width, \
			cub->map.height)))
		exit_game(cub, 5);
	if (!(cub->get_data = (int *)mlx_get_data_addr(cub->new_image, \
			&cub->bits_per_pixel, &cub->size_line, &cub->endian)))
		exit_game(cub, 5);
	if (!(cub->rs.dist_wall = ft_calloc(sizeof(double), cub->map.width)))
		exit_game(cub, 6);
	raycasting(cub);
	raysprite(cub);
	if (cub->rs.dist_wall)
	{
		free(cub->rs.dist_wall);
		cub->rs.dist_wall = NULL;
	}
	if (cub->save == 1)
		bmp(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->new_image, 0, 0);
	mlx_do_sync(cub->mlx_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->new_image);
}

static void	init_game(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!(cub->mlx_ptr = mlx_init()))
		exit_game(cub, 5);
	mlx_get_screen_size(cub->mlx_ptr, &x, &y);
	if (cub->map.width > x)
		cub->map.width = x;
	if (cub->map.height > y)
		cub->map.height = y;
	if (cub->save == 0)
	{
		if (!(cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->map.width, \
					cub->map.height, "Cub3d")))
			exit_game(cub, 5);
	}
	init_textures(cub);
	init_frame(cub);
	mlx_hook(cub->win_ptr, 2, 1, &key_press, cub);
	mlx_hook(cub->win_ptr, 3, 2, &key_release, cub);
	mlx_hook(cub->win_ptr, 33, 0, &key_exit, cub);
	mlx_loop_hook(cub->mlx_ptr, &movement, cub);
	mlx_loop(cub->mlx_ptr);
}

static void	orientation(t_cub *cub)
{
	if (cub->map.orientation == 'N')
	{
		cub->rc.dir_x = 0;
		cub->rc.dir_y = -1;
	}
	else if (cub->map.orientation == 'S')
	{
		cub->rc.dir_x = 0;
		cub->rc.dir_y = 1;
	}
	else if (cub->map.orientation == 'W')
	{
		cub->rc.dir_x = -1;
		cub->rc.dir_y = 0;
	}
	else if (cub->map.orientation == 'E')
	{
		cub->rc.dir_x = 1;
		cub->rc.dir_y = 0;
	}
	cub->rc.plan_x = -0.66 * cub->rc.dir_y;
	cub->rc.plan_y = 0.66 * cub->rc.dir_x;
}

int			main(int argc, char **argv)
{
	t_cub	*cub;
	int		len;

	if (!(cub = (t_cub *)malloc(sizeof(t_cub))))
		exit_game(cub, 6);
	ft_bzero(cub, sizeof(t_cub));
	if (argc < 2 || argc > 3)
		exit_game(cub, 1);
	else if (!(len = ft_strlen(argv[1]) - 4))
		exit_game(cub, 2);
	else if (ft_strncmp(argv[1] + len, ".cub", 4))
		exit_game(cub, 3);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
			cub->save = 1;
		else
			exit_game(cub, 4);
	}
	read_file(argv, cub);
	orientation(cub);
	init_game(cub);
	return (0);
}
