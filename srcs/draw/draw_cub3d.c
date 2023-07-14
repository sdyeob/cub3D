/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:43:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/14 21:53:20 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx_opengl_20191021/mlx.h"
#include "../../includes/struct.h"
#include "../../includes/drawing_consts.h"
#include "../../includes/drawing_struct.h"
#include "../../includes/drawing.h"

static void	init_textures(t_draw *draw, t_map_inf *map_info);
static void	init_cf_color(t_draw *draw, t_map_inf *map_info);
static void	init_draw(t_draw *draw, t_map_inf *map_info);

void	draw_cub3d(t_map_inf *map_info)
{
	t_draw	draw;

	init_draw(&draw, map_info);
	mlx_hook(draw.win_ptr, 2, 0, key_down, &draw);
	mlx_loop_hook(draw.mlx_ptr, render_frame, &draw);
	mlx_loop(draw.mlx_ptr);
}

static void	init_draw(t_draw *draw, t_map_inf *map_info)
{
	draw->map = map_info->map;
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window(draw->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "cub3D");
	draw->img.img_ptr = mlx_new_image(draw->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	draw->img.addr = mlx_get_data_addr(draw->img.img_ptr, \
	&(draw->img.bits_per_pixel), &(draw->img.line_length), &(draw->img.endian));
	draw->pos.x = map_info->player_loc_x + 0.5;
	draw->pos.y = map_info->player_loc_y + 0.5;
	draw->dir.x = 0;
	draw->dir.y = 0;
	if (map_info->player_direct == 'E')
		draw->dir.x = 1;
	else if (map_info->player_direct == 'W')
		draw->dir.x = -1;
	else if (map_info->player_direct == 'S')
		draw->dir.y = -1;
	else
		draw->dir.y = 1;
	init_textures(draw, map_info);
	init_cf_color(draw, map_info);
}

static void	init_textures(t_draw *draw, t_map_inf *map_info)
{
	t_img			*img;

	img = &(draw->ewsn[east]);
	img->img_ptr = mlx_xpm_file_to_image(draw->mlx_ptr, \
	map_info->identifier.e, &(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img_ptr, \
	&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img = &(draw->ewsn[west]);
	img->img_ptr = mlx_xpm_file_to_image(draw->mlx_ptr, \
	map_info->identifier.w, &(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img_ptr, \
	&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img = &(draw->ewsn[south]);
	img->img_ptr = mlx_xpm_file_to_image(draw->mlx_ptr, \
	map_info->identifier.s, &(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img_ptr, \
	&(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img = &(draw->ewsn[north]);
	img->img_ptr = mlx_xpm_file_to_image(draw->mlx_ptr, \
	map_info->identifier.n, &(img->width), &(img->height));
	img->addr = mlx_get_data_addr(img->img_ptr, \
	&(img->bits_per_pixel), &(img->line_length), &(img->endian));
}

static void	init_cf_color(t_draw *draw, t_map_inf *map_info)
{
	int	*cf;

	cf = map_info->identifier.c;
	draw->c_color = create_trgb(0, cf[0], cf[1], cf[2]);
	cf = map_info->identifier.f;
	draw->f_color = create_trgb(0, cf[0], cf[1], cf[2]);
}
