/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:41:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 21:10:10 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "drawing.h"
#include "drawing_struct.h"
#include "drawing_consts.h"

static void	free_map_inf(t_map_inf *map_inf);

int	destroy(t_draw *draw)
{
	mlx_destroy_window(draw->mlx_ptr, draw->win_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->img.img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[east].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[west].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[south].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[north].img_ptr);
	free_map_inf(draw->map_inf);
	exit(0);
	return (0);
}

int	key_down(int keycode, t_draw *draw)
{
	if (keycode == KEY_ESC)
		destroy(draw);
	else if (keycode == KEY_LEFT)
		draw->move.ro_left = 1;
	else if (keycode == KEY_RIGHT)
		draw->move.ro_right = 1;
	else if (keycode == KEY_W)
		draw->move.front = 1;
	else if (keycode == KEY_A)
		draw->move.left = 1;
	else if (keycode == KEY_S)
		draw->move.back = 1;
	else if (keycode == KEY_D)
		draw->move.right = 1;
	return (0);
}

int	key_up(int keycode, t_draw *draw)
{
	if (keycode == KEY_LEFT)
		draw->move.ro_left = 0;
	else if (keycode == KEY_RIGHT)
		draw->move.ro_right = 0;
	else if (keycode == KEY_W)
		draw->move.front = 0;
	else if (keycode == KEY_A)
		draw->move.left = 0;
	else if (keycode == KEY_S)
		draw->move.back = 0;
	else if (keycode == KEY_D)
		draw->move.right = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_draw *draw)
{
	draw->dir = rotate_vec(draw->dir, \
	(x - draw->mouse_pos.x) * MOUSE_ANGLE_RATIO);
	mlx_mouse_move(draw->win_ptr, W_WIDTH / 2, W_HEIGHT / 2);
	draw->mouse_pos.x = W_WIDTH / 2;
	draw->mouse_pos.y = y;
	return (0);
}

static void	free_map_inf(t_map_inf *map_inf)
{
	int	i;

	if (map_inf->identifier.n)
		free(map_inf->identifier.n);
	if (map_inf->identifier.w)
		free(map_inf->identifier.w);
	if (map_inf->identifier.e)
		free(map_inf->identifier.e);
	if (map_inf->identifier.s)
		free(map_inf->identifier.s);
	if (map_inf->map)
	{
		i = -1;
		while (map_inf->map[++i])
			free(map_inf->map[i]);
		free(map_inf->map);
	}
}
