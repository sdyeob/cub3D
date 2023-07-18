/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:41:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/18 16:04:22 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/drawing.h"
#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"

int	destroy(t_draw *draw)
{
	mlx_destroy_window(draw->mlx_ptr, draw->win_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->img.img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[east].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[west].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[south].img_ptr);
	mlx_destroy_image(draw->mlx_ptr, draw->ewsn[north].img_ptr);
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
	else if (keycode == KEY_SPACE)
		return (0);
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
	mlx_mouse_move(draw->win_ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	draw->mouse_pos.x = WIN_WIDTH / 2;
	draw->mouse_pos.y = y;
	return (0);
}