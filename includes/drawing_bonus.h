/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:35:27 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:48:44 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_BONUS_H
# define DRAWING_BONUS_H

# include "drawing_struct.h"
# include "map_struct.h"

//draw_cub3d.c
void	draw_cub3d(t_map_inf *map_info);

//color.c
int		get_tex_color(t_draw *draw, int x, int y);
void	my_pixel_put(t_img *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

//door.c
void	door(t_draw *draw);
void	door_change(t_draw *draw);
int		door_or_wall(t_cal *cal, t_draw *draw);
void	door_tex_correction(t_cal *cal, t_draw *draw);

//move.c
void	move_fov(t_draw *draw);

//render_frame.c
int		render_frame(t_draw *draw);
void	render_minimap(t_draw *draw);

//render_frame_utils.c
void	calculate_vars(t_cal *cal, t_draw *draw);
void	cal_perp_dist_y_range(t_cal *cal, t_draw *draw);
void	cal_tex_x(t_cal *cal, t_draw *draw);

//hook.c
int		key_down(int keycode, t_draw *draw);
int		key_up(int keycode, t_draw *draw);
int		destroy(t_draw *draw);
int		mouse_hook(int x, int y, t_draw *draw);

//vector.c
t_vec_d	get_plane_dir_vec(t_vec_d dir);
t_vec_d	rotate_vec(t_vec_d dir, double angle);
t_vec_d	add_vec(t_vec_d a, t_vec_d b);
t_vec_d	mult_vec(double scalar, t_vec_d vec);
t_vec_i	init_vec_i(int x, int y);

#endif