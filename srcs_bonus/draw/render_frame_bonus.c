/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:05:41 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:36 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "drawing_struct_bonus.h"
#include "drawing_consts_bonus.h"
#include "drawing_bonus.h"

static void	color_wall(t_draw *draw, int x);

int	render_frame(t_draw *draw)
{
	t_cal		cal;
	int			x;
	double		plane_coef;

	move_fov(draw);
	cal.plane = get_plane_dir_vec(mult_vec(PLANE_SIZE, draw->dir));
	x = -1;
	while (++x < W_WIDTH)
	{
		plane_coef = 2 * x / (double)W_WIDTH - 1;
		cal.ray_dir = add_vec(draw->dir, mult_vec(plane_coef, cal.plane));
		calculate_vars(&cal, draw);
		door_tex_correction(&cal, draw);
		color_wall(draw, x);
	}
	render_minimap(draw);
	mlx_put_image_to_window(draw->mlx_ptr, draw->win_ptr, \
	draw->img.img_ptr, 0, 0);
	if (draw->door.is_moving)
		door_change(draw);
	return (0);
}

static void	color_wall(t_draw *draw, int x)
{
	double	step;
	double	tex_y_pos;
	int		y;

	if (draw->hit_where == '1')
		step = 1.0 * draw->ewsn[draw->side].height / draw->wall_height;
	else
		step = 1.0 * draw->door.img.height / draw->wall_height;
	tex_y_pos = (draw->y_start - W_HEIGHT / 2 + draw->wall_height / 2) * step;
	y = -1;
	while (++y < W_HEIGHT)
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
