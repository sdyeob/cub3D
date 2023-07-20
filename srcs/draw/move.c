/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:26 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 19:47:42 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing.h"

static int	is_wall(char **map, double y, double x);

void	move_fov(t_draw *draw)
{
	t_vec_d	new_pos;

	if (draw->door.is_moving)
		return ;
	new_pos = add_vec(draw->pos, \
	mult_vec((draw->move.front - draw->move.back) * VELOCITY, draw->dir));
	new_pos = add_vec(new_pos, mult_vec((draw->move.right - \
	draw->move.left) * VELOCITY, get_plane_dir_vec(draw->dir)));
	if (!is_wall(draw->map, new_pos.y, draw->pos.x))
		draw->pos.y = new_pos.y;
	if (!is_wall(draw->map, draw->pos.y, new_pos.x))
		draw->pos.x = new_pos.x;
	draw->dir = rotate_vec(draw->dir, \
	(draw->move.ro_right - draw->move.ro_left) * ANGLE_VELOCITY);
}

static int	is_wall(char **map, double y, double x)
{
	int	row;
	int	col;

	row = (int)y;
	col = (int)x;
	if (map[row][col] == '0' || 'O' == map[row][col])
		return (0);
	return (1);
}
