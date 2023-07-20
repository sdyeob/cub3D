/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:26:33 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 16:10:02 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing.h"
#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"

static void	init_door(t_draw *draw, int row, int col, char c);

void	door(t_draw *draw)
{
	char	c;
	int		row;
	int		col;
	t_vec_d	door_pos;

	door_pos = add_vec(draw->pos, \
	mult_vec(DOOR_SEARCH_RANGE, draw->dir));
	row = (int)door_pos.y;
	col = (int)door_pos.x;
	c = draw->map[row][col];
	if (c == 'C' || c == 'M' || c == 'O')
		init_door(draw, row, col, c);
}

static void	init_door(t_draw *draw, int row, int col, char c)
{
	draw->door.is_moving = 1;
	draw->door.row = row;
	draw->door.col = col;
	draw->map[row][col] = 'M';
	if (c == 'C')
	{
		draw->door.degree = DOOR_MIN_DEGREE;
		draw->door.stat = opening;
	}
	else if (c == 'M')
		draw->door.stat = !draw->door.stat;
	else if (c == 'O')
	{
		draw->door.degree = DOOR_MAX_DEGREE;
		draw->door.stat = closing;
	}
}

void	door_change(t_draw *draw)
{
	if (draw->door.stat == opening)
	{
		if (++draw->door.degree == DOOR_MAX_DEGREE)
		{
			draw->door.is_moving = 0;
			draw->map[draw->door.row][draw->door.col] = 'O';
		}
	}
	else
	{
		if (--draw->door.degree == DOOR_MIN_DEGREE)
		{
			draw->door.is_moving = 0;
			draw->map[draw->door.row][draw->door.col] = 'C';
		}
	}
}

int	door_or_wall(t_cal *cal, t_draw *draw)
{
	if (draw->map[cal->map_pos.y][cal->map_pos.x] == 'O')
		return (1);
	else if (draw->map[cal->map_pos.y][cal->map_pos.x] == '1')
		return (draw->hit_where = '1', 0);
	else if (draw->map[cal->map_pos.y][cal->map_pos.x] == 'C')
		return (draw->hit_where = 'C', 0);
	draw->hit_where = 'M';
	cal_perp_dist_y_range(cal, draw);
	cal_tex_x(cal, draw);
	if (cal->wall_x <= 0.5 - 0.5 * draw->door.degree / DOOR_MAX_DEGREE)
		return (0);
	else if (cal->wall_x >= 0.5 + 0.5 * draw->door.degree / DOOR_MAX_DEGREE)
		return (0);
	return (1);
}
