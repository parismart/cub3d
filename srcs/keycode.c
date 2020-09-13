/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parmarti <parmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:02:35 by parmarti          #+#    #+#             */
/*   Updated: 2020/09/10 12:46:28 by parmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_exit(t_cub *cub)
{
	exit_game(cub, 0);
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 0;
	if (keycode == S)
		cub->mv.down = 0;
	if (keycode == D)
		cub->mv.right = 0;
	if (keycode == A)
		cub->mv.left = 0;
	if (keycode == LEFT)
		cub->mv.rot_right = 0;
	if (keycode == RIGHT)
		cub->mv.rot_left = 0;
	if (keycode == ESC)
		key_exit(cub);
	return (0);
}

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == W)
		cub->mv.up = 1;
	if (keycode == S)
		cub->mv.down = 1;
	if (keycode == D)
		cub->mv.right = 1;
	if (keycode == A)
		cub->mv.left = 1;
	if (keycode == LEFT)
		cub->mv.rot_right = 1;
	if (keycode == RIGHT)
		cub->mv.rot_left = 1;
	return (0);
}
