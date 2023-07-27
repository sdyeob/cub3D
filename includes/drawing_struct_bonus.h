/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:30:22 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/27 21:35:16 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_STRUCT_BONUS_H
# define DRAWING_STRUCT_BONUS_H

# include "parsing_struct_bonus.h"

typedef struct s_vec_d
{
	double	x;
	double	y;
}	t_vec_d;

typedef struct s_vec_i
{
	int	x;
	int	y;
}	t_vec_i;

typedef enum e_side
{
	east = 0,
	west = 1,
	south = 2,
	north = 3
}	t_side;

typedef struct s_move
{
	int	left;
	int	right;
	int	front;
	int	back;
	int	ro_left;
	int	ro_right;
}	t_move;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef enum e_door_stat
{
	opening = 0,
	closing = 1
}	t_door_stat;

typedef struct s_door
{
	t_img		img;
	t_door_stat	stat;
	int			is_moving;
	int			degree;
	int			row;
	int			col;
}	t_door;

typedef struct s_draw
{
	char		**map;
	int			m_height;
	int			m_width;
	int			f_color;
	int			c_color;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img		ewsn[4];
	t_door		door;
	t_vec_d		pos;
	t_vec_d		dir;
	t_vec_i		mouse_pos;
	int			hold_mouse;
	char		hit_where;
	t_side		side;
	int			wall_height;
	int			y_start;
	int			y_end;
	int			tex_x;
	t_move		move;
	t_map_inf	*map_inf;
}	t_draw;

typedef struct s_minimap
{
	int	h;
	int	w;
	int	row;
	int	col;
}	t_minimap;

typedef struct s_cal
{
	t_vec_d		plane;
	t_vec_d		ray_dir;
	t_vec_i		map_pos;
	t_vec_i		step;
	int			hit;
	double		side_ratio_x;
	double		side_ratio_y;
	double		delta_ratio_x;
	double		delta_ratio_y;
	double		wall_camera_plane_dist;
	double		wall_x;
}	t_cal;

#endif
