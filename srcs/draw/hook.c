/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:41:42 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/12 17:35:35 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/drawing_struct.h"

#define KEY_ESC 53
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126

int	destroy(t_draw *all)
{
	mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	exit(0);
	return (0);
}

int	key_down(int keycode, t_draw *all)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(0);
	}
	else if (keycode == KEY_LEFT)
	{
		all->move.left = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		all->move.right = 1;
	}
	else if (keycode == KEY_DOWN)
	{
		all->move.down = 1;
	}
	else if (keycode == KEY_UP)
	{
		all->move.up = 1;
	}
	return (0);
}

int	key_up(int keycode, t_draw *all)
{
	if (keycode == KEY_LEFT)
	{
		all->move.left = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		all->move.right = 0;
	}
	else if (keycode == KEY_DOWN)
	{
		all->move.down = 0;
	}
	else if (keycode == KEY_UP)
	{
		all->move.up = 0;
	}
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_draw *all)
{
	if (mousecode == MOUSE_SCROLL_UP)
	{
		update_mid(x, y, all);
		if (all->pos.accum * 1.1 < 10000000000)
			all->pos.accum *= 1.1;
	}
	else if (mousecode == MOUSE_SCROLL_DOWN)
	{
		update_mid(x, y, all);
		if (all->pos.accum / 1.1 > 1)
			all->pos.accum /= 1.1;
	}
	return (0);
}