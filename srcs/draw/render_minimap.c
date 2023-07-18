/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:59:02 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/18 21:28:56 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "drawing.h"
#include "drawing_struct.h"
#include "drawing_consts.h"

static inline int	is_in_map(t_draw *draw, int player_row, int player_col);
static inline int	is_player(int w, int h);
static inline int	get_render_object(t_draw *draw, t_minimap m);

void	render_minimap(t_draw *draw)
{
	int			object_color;
	t_minimap	m;

	m.h = -1;
	while (++(m.h) < M_HEIGHT)
	{
		m.w = -1;
		while (++(m.w) < M_WIDTH)
		{
			m.row = floor(draw->pos.y + (m.h - M_HEIGHT / 2) * M_BPP);
			m.col = floor(draw->pos.x + (m.w - M_WIDTH / 2) * M_BPP);
			object_color = get_render_object(draw, m);
			my_pixel_put(&draw->img, M_SEP + m.w, M_SEP + m.h, object_color);
		}
	}
}

static inline int	is_in_map(t_draw *draw, int player_row, int player_col)
{
	if ((0 <= player_col && player_col < draw->m_width) \
		&& (0 <= player_row && player_row < draw->m_height))
		return (1);
	else
		return (0);
}

static inline int	get_render_object(t_draw *draw, t_minimap m)
{
	if (is_in_map(draw, m.row, m.col))
	{
		if (is_player(m.w, m.h))
			return (PLAYER_COLOR);
		else if (draw->map[m.row][m.col] == '1')
			return (WALL_COLOR);
		else if (draw->map[m.row][m.col] == '0')
			return (FLOOR_COLOR);
		else if (draw->map[m.row][m.col] == ' ')
			return (SPACE_COLOR);
		else
			return (DOOR_COLOR);
	}
	else
		return (OUT_OF_MAP_COLOR);
}

static inline int	is_player(int w, int h)
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
