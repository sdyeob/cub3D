/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:03:35 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/17 20:23:50 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/drawing_struct.h"

int	get_tex_color(t_draw *draw, int x, int y)
{
	t_img	data;
	char	*dst;

	data = draw->ewsn[draw->side];
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
