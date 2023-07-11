/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:43:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/11 21:01:05 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing_struct.h"

void	draw_cub3d(t_map_inf *map_info)
{
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	img.img_ptr = mlx_new_image(mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &(img.bits_per_pixel), \
	&(img.line_length), &(img.endian));

	mlx_loop(mlx_ptr);
}
