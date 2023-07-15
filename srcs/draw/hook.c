/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:41:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/15 22:34:07 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/drawing_struct.h"

#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

int	destroy(t_draw *draw)
{
	mlx_destroy_window(draw->mlx_ptr, draw->win_ptr);
	// mlx_destroy_image(draw->mlx_ptr, draw->img.img_ptr);
	// mlx_destroy_image(draw->mlx_ptr, draw->ewsn[east].img_ptr);
	// mlx_destroy_image(draw->mlx_ptr, draw->ewsn[west].img_ptr);
	// mlx_destroy_image(draw->mlx_ptr, draw->ewsn[south].img_ptr);
	// mlx_destroy_image(draw->mlx_ptr, draw->ewsn[north].img_ptr);
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

// int	mouse_hook(int mousecode, int x, int y, t_draw *all)
// {
// 	if (mousecode == MOUSE_SCROLL_UP)
// 	{
// 		update_mid(x, y, all);
// 		if (all->pos.accum * 1.1 < 10000000000)
// 			all->pos.accum *= 1.1;
// 	}
// 	else if (mousecode == MOUSE_SCROLL_DOWN)
// 	{
// 		update_mid(x, y, all);
// 		if (all->pos.accum / 1.1 > 1)
// 			all->pos.accum /= 1.1;
// 	}
// 	return (0);
// }