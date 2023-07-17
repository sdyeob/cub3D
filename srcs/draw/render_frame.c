/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:05:41 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/17 20:23:50 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing.h"

static void	color_wall(t_draw *draw, int x);
static void	move_fov(t_draw *draw);

int	render_frame(t_draw *draw)
{
	t_cal		cal;
	int			x;
	double		plane_coef;

	move_fov(draw);
	cal.plane = get_plane_vec(draw->dir);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		plane_coef = 2 * x / (double)WIN_WIDTH - 1;
		cal.ray_dir = add_vec(draw->dir, mult_vec(plane_coef, cal.plane));
		calculate_vars(&cal, draw);
		color_wall(draw, x);
	}
	render_minimap(draw);
	mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, \
	draw->img.img_ptr, 0, 0);
	return (0);
}

static void	move_fov(t_draw *draw)
{
	draw->pos = add_vec(draw->pos, \
	mult_vec((draw->move.front - draw->move.back) * VELOCITY, draw->dir));
	draw->pos = add_vec(draw->pos, mult_vec((draw->move.right - \
	draw->move.left) * VELOCITY, get_plane_vec(draw->dir)));
	draw->dir = rotate_vec(draw->dir, \
	(draw->move.ro_right - draw->move.ro_left) * ANGLE_VELOCITY);
}

static void	color_wall(t_draw *draw, int x)
{
	double	step;
	double	tex_y_pos;
	int		y;

	step = 1.0 * draw->ewsn[draw->side].height / draw->wall_height;
	tex_y_pos = (draw->y_start - WIN_HEIGHT / 2 + draw->wall_height / 2) * step;
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		if (y < draw->y_start)
			my_pixel_put(&(draw->img), x, y, draw->c_color);
		else if (y >= draw->y_end)
			my_pixel_put(&(draw->img), x, y, draw->f_color);
		else
		{
			my_pixel_put(&(draw->img), x, y, \
			get_tex_color(draw, draw->tex_x, (int)tex_y_pos));
			tex_y_pos += step;
		}
	}
}
