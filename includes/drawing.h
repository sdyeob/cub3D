/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:35:27 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/17 15:55:23 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "drawing_struct.h"
# include "struct.h"

//draw_cub3d.c
void	draw_cub3d(t_map_inf *map_info);

//color.c
int		get_tex_color(t_draw *draw, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

//render_frame.c
int		render_frame(t_draw *draw);
void	render_minimap(t_draw *draw);

//render_frame_utils.c
void	calculate_vars(t_cal *cal, t_draw *draw);

//hook.c
int		key_down(int keycode, t_draw *draw);
int		key_up(int keycode, t_draw *draw);
int		destroy(t_draw *draw);

//vector.c
t_vec_d	get_plane_vec(t_vec_d dir);
t_vec_d	rotate_vec(t_vec_d dir, double angle);
t_vec_d	add_vec(t_vec_d a, t_vec_d b);
t_vec_d	mult_vec(double scalar, t_vec_d vec);
t_vec_i	init_vec_i(int x, int y);

#endif