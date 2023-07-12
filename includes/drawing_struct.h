/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:30:22 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/12 21:09:07 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_STRUCT_H
# define DRAWING_STRUCT_H

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
	east,
	west,
	south,
	north
}	t_side;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_draw
{
	char		**map;
	int			f_color;
	int			c_color;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img		ewsn[4];
	t_vec_d		pos;
	t_vec_d		dir;
}	t_draw;

typedef struct s_cal
{
	t_vec_d		plane;
	t_vec_d		ray_dir;
	t_vec_i		map_pos;
	t_vec_i		step;
	t_side		side;
	int			hit;
	double		side_ratio_x;
	double		side_ratio_y;
	double		delta_ratio_x;
	double		delta_ratio_y;
}	t_cal;

#endif