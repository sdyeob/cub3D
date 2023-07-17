/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:59:02 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/17 20:34:00 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "drawing.h"
#include "drawing_struct.h"
#include "drawing_consts.h"

static int	is_in_map(t_draw *draw, int i, int j);
static int	is_player_in_map(int w, int h);

void	render_minimap(t_draw *draw)
{
	int	h;
	int w;
	int	row;
	int	col;

	h = -1;
	while (++h < M_HEIGHT)
	{
		w = -1;
		while (++w < M_WIDTH)
		{
			row = floor(draw->pos.y + (h - M_HEIGHT / 2) * M_BLOCK_PER_PIXEL);
			col = floor(draw->pos.x + (w - M_WIDTH / 2) * M_BLOCK_PER_PIXEL);
			if (is_in_map(draw, row, col))
			{
				if (is_player_in_map(w, h))
					my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 0xFFFFFF);
				else if (draw->map[row][col] == '1')
					my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 0x000099);
				else if (draw->map[row][col] == '0')
					my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 0x0033FF);
				else if (draw->map[row][col] == ' ')
					my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 0x6699FF);
				// else
				// 	my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 150 << 24 | 220);
			}
			else
				my_pixel_put(&draw->img, M_SEP + w, M_SEP + h, 100 << 24 | 220);
		}
	}
}

static int	is_in_map(t_draw *draw, int player_row, int player_col)
{
	if ((0 <= player_col && player_col < draw->m_width) \
		&& (0 <= player_row && player_row < draw->m_height))
		return (1);
	else
		return (0);
}

static int	is_player_in_map(int w, int h)
{
	if ((M_WIDTH - M_PLAYER_RANGE) / 2 > w)
		return (0);
	else if ((M_WIDTH + M_PLAYER_RANGE) / 2 <= w)
		return (0);
	else if ((M_HEIGHT - M_PLAYER_RANGE) / 2 > h)
		return (0);
	else if ((M_HEIGHT + M_PLAYER_RANGE) / 2 <= h)
		return (0);
	else
		return (1);
}
