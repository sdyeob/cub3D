/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:43:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/12 21:09:32 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing_struct.h"
#include "../../includes/drawing.h"

void	draw_cub3d(t_map_inf *map_info)
{
	t_draw	draw;

	init_draw(&draw, map_info);
	
	mlx_loop_hook(draw.mlx_ptr, render_frame, &draw);
	mlx_loop(draw.mlx_ptr);
}

void	init_draw(t_draw *draw, t_map_inf *map_info)
{
	draw->map = map_info->map;
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window(draw->mlx_ptr, \ 
	WIN_WIDTH, WIN_HEIGHT, "cub3D");
	draw->img.img_ptr = mlx_new_image(draw->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	draw->img.addr = mlx_get_data_addr(draw->img.img_ptr, \
	&(draw->img.bits_per_pixel), &(draw->img.line_length), &(draw->img.endian));
}
