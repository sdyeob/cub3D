/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:05:41 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/12 21:10:36 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing.h"

static void	cal_ratios(t_cal *cal, t_draw *draw);

int	render_frame(t_draw *draw)
{
	t_cal		cal;
	int			x;
	double		plane_coef;

	cal.plane = get_plane_vec(draw->dir);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		plane_coef = 2 * x / (double)WIN_WIDTH - 1;
		cal.ray_dir = add_vec(draw->dir, mult_vec(plane_coef, cal.plane));
		cal_ratios(&cal, draw);
	}
}

static void	cal_ratios(t_cal *cal, t_draw *draw)
{
	if (cal->ray_dir.x == 0 || cal->ray_dir.y == 0)
	{
		cal->delta_ratio_x
	}
	cal->delta_ratio_x = fabs(1 / cal->ray_dir.x);
	cal->delta_ratio_y = fabs(1 / cal->ray_dir.y);
}

static void	dda(t_cal *cal, t_draw *draw)
{
	cal->hit = 0;
	while (cal->hit == 0)
	{
		if (cal->side_ratio_x < cal->side_ratio_y)
		{
			cal->side_ratio_x += cal->delta_ratio_x;
			cal->map_pos.x += cal->step.x;
			if (draw->dir.x > 0)
				cal->side = east;
			else
				cal->side = west;
		}
		else
		{
			cal->side_ratio_x += cal->delta_ratio_x;
			cal->map_pos.x += cal->step.x;
			if (draw->dir.y > 0)
				cal->side = north;
			else
				cal->side = south;
		}
		if (draw->map[cal->map_pos.x][cal->map_pos.y] > 0)
			cal->hit = 1;
	}
}
