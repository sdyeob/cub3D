/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:03:35 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:37 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing_struct_bonus.h"

int	get_tex_color(t_draw *draw, int x, int y)
{
	t_img	data;
	char	*dst;

	if (draw->hit_where == '1')
		data = draw->ewsn[draw->side];
	else
		data = draw->door.img;
	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	return (*(int *)dst);
}

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
