/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:29:44 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:57 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "drawing_struct.h"
#include "drawing_consts.h"
#include "drawing.h"

static void	cal_step_side_ratio(t_cal *cal, t_draw *draw);
static void	dda(t_cal *cal, t_draw *draw);

void	calculate_vars(t_cal *cal, t_draw *draw)
{
	cal->map_pos = init_vec_i((int)draw->pos.x, (int)draw->pos.y);
	if (cal->ray_dir.x == 0)
		cal->delta_ratio_y = 0;
	else
	{
		if (cal->ray_dir.y == 0)
			cal->delta_ratio_y = 1;
		else
			cal->delta_ratio_y = fabs(1 / cal->ray_dir.y);
	}
	if (cal->ray_dir.y == 0)
		cal->delta_ratio_x = 0;
	else
	{
		if (cal->ray_dir.x == 0)
			cal->delta_ratio_x = 1;
		else
			cal->delta_ratio_x = fabs(1 / cal->ray_dir.x);
	}
	cal_step_side_ratio(cal, draw);
	dda(cal, draw);
	cal_perp_dist_y_range(cal, draw);
	cal_tex_x(cal, draw);
}

static void	cal_step_side_ratio(t_cal *cal, t_draw *draw)
{
	if (cal->ray_dir.x < 0)
	{
		cal->step.x = -1;
		cal->side_ratio_x = (draw->pos.x - cal->map_pos.x) * cal->delta_ratio_x;
	}
	else
	{
		cal->step.x = 1;
		cal->side_ratio_x = \
		(cal->map_pos.x + 1.0 - draw->pos.x) * cal->delta_ratio_x;
	}
	if (cal->ray_dir.y < 0)
	{
		cal->step.y = -1;
		cal->side_ratio_y = (draw->pos.y - cal->map_pos.y) * cal->delta_ratio_y;
	}
	else
	{
		cal->step.y = 1;
		cal->side_ratio_y = \
		(cal->map_pos.y + 1.0 - draw->pos.y) * cal->delta_ratio_y;
	}
}

static void	dda(t_cal *cal, t_draw *draw)
{
	cal->hit = 1;
	while (cal->hit)
	{
		if (cal->side_ratio_x < cal->side_ratio_y)
		{
			cal->side_ratio_x += cal->delta_ratio_x;
			cal->map_pos.x += cal->step.x;
			if (cal->ray_dir.x > 0)
				draw->side = east;
			else
				draw->side = west;
		}
		else
		{
			cal->side_ratio_y += cal->delta_ratio_y;
			cal->map_pos.y += cal->step.y;
			if (cal->ray_dir.y > 0)
				draw->side = north;
			else
				draw->side = south;
		}
		if (draw->map[cal->map_pos.y][cal->map_pos.x] > '0')
			cal->hit = door_or_wall(cal, draw);
	}
}

void	cal_perp_dist_y_range(t_cal *cal, t_draw *draw)
{
	if (draw->side == east || draw->side == west)
		cal->wall_camera_plane_dist = \
		(cal->map_pos.x - draw->pos.x + (1 - cal->step.x) / 2) / cal->ray_dir.x;
	else
		cal->wall_camera_plane_dist = \
		(cal->map_pos.y - draw->pos.y + (1 - cal->step.y) / 2) / cal->ray_dir.y;
	draw->wall_height = (int)(W_HEIGHT * BLOCK_PER_WIN \
							/ cal->wall_camera_plane_dist);
	draw->y_start = -draw->wall_height / 2 + W_HEIGHT / 2;
	draw->y_end = draw->wall_height / 2 + W_HEIGHT / 2;
	if (draw->y_start < 0)
		draw->y_start = 0;
	if (draw->y_end >= W_HEIGHT)
		draw->y_end = W_HEIGHT - 1;
}

void	cal_tex_x(t_cal *cal, t_draw *draw)
{
	if (draw->side == east || draw->side == west)
		cal->wall_x = \
		draw->pos.y + cal->wall_camera_plane_dist * cal->ray_dir.y;
	else
		cal->wall_x = \
		draw->pos.x + cal->wall_camera_plane_dist * cal->ray_dir.x;
	cal->wall_x -= floor(cal->wall_x);
	if (draw->hit_where == '1')
	{
		draw->tex_x = (int)(cal->wall_x * draw->ewsn[draw->side].width);
		if (draw->side == east || draw->side == south)
			draw->tex_x = draw->ewsn[draw->side].width - draw->tex_x - 1;
	}
	else
	{
		draw->tex_x = (int)(cal->wall_x * draw->door.img.width);
		if (draw->side == east || draw->side == south)
			draw->tex_x = draw->door.img.width - draw->tex_x - 1;
	}
}
