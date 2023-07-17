/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:59:02 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/17 17:59:45 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"
#include "drawing_struct.h"

static int	is_in_map(t_draw *draw, int i, int j);

void	render_minimap(t_draw *draw)
{
	int	i;
	int j;
	int	player_row;
	int	player_col;

	i = -1;
	while (++i < 200)
	{
		j = -1;
		while (++j < 200)
		{
			player_col = (int)draw->pos.x + (j - 100) / 20;
			player_row = (int)draw->pos.y + (i - 100) / 20;
			if (is_in_map(draw, player_row, player_col))
			{
				if ((95 <= i && i < 105) && (95 <= j && j < 105))
					my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 0xFFFFFF);
				else if (draw->map[player_row][player_col] == '1')
					my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 0x000099);
				else if (draw->map[player_row][player_col] == '0')
					my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 0x0033FF);
				else if (draw->map[player_row][player_col] == ' ')
					my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 0x6699FF);
				// else
				// 	my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 150 << 24 | 220);
			}
			else
				my_mlx_pixel_put(&draw->img, 20 + j, 20 + i, 100 << 24 | 220);
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