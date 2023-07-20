/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:43:01 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 21:12:23 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map_struct.h"
#include "drawing_consts.h"
#include "drawing_struct.h"
#include "drawing.h"

static void	init_textures(t_draw *draw, t_map_inf *map_info);
static void	init_color_move(t_draw *draw, t_map_inf *map_info);
static void	init_draw(t_draw *draw, t_map_inf *map_info);

void	draw_cub3d(t_map_inf *map_info)
{
	t_draw	draw;

	init_draw(&draw, map_info);
	mlx_hook(draw.win_ptr, 2, 0, key_down, &draw);
	mlx_hook(draw.win_ptr, 3, 0, key_up, &draw);
	mlx_hook(draw.win_ptr, 6, 0, mouse_hook, &draw);
	mlx_hook(draw.win_ptr, 17, 0, destroy, &draw);
	mlx_loop_hook(draw.mlx_ptr, render_frame, &draw);
	mlx_loop(draw.mlx_ptr);
}

static void	init_draw(t_draw *draw, t_map_inf *map_info)
{
	draw->map_inf = map_info;
	draw->map = map_info->map;
	draw->m_height = map_info->m_height;
	draw->m_width = map_info->m_width;
	draw->mlx_ptr = mlx_init();
	draw->win_ptr = mlx_new_window(draw->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	draw->img.img_ptr = mlx_new_image(draw->mlx_ptr, W_WIDTH, W_HEIGHT);
	draw->img.addr = mlx_get_data_addr(draw->img.img_ptr, \
	&(draw->img.bits_per_pixel), &(draw->img.line_length), &(draw->img.endian));
	draw->map[map_info->player_loc_y][map_info->player_loc_x] = '0';
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
	init_color_move(draw, map_info);
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

static void	init_color_move(t_draw *draw, t_map_inf *map_info)
{
	int	*cf;

	cf = map_info->identifier.c;
	draw->c_color = create_trgb(0, cf[0], cf[1], cf[2]);
	cf = map_info->identifier.f;
	draw->f_color = create_trgb(0, cf[0], cf[1], cf[2]);
	draw->move.ro_left = 0;
	draw->move.ro_right = 0;
	draw->move.left = 0;
	draw->move.right = 0;
	draw->move.front = 0;
	draw->move.back = 0;
	mlx_mouse_get_pos(draw->win_ptr, \
	&draw->mouse_pos.x, &draw->mouse_pos.y);
	mlx_mouse_hide();
}
