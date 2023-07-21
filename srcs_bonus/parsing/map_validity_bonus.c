/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:18:22 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/21 20:22:02 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_struct_bonus.h"
#include "err_detect_bonus.h"

static void	is_close(t_map_inf *map_inf, int height, int width);

void	map_validity_check(t_map_inf *map_inf)
{
	int	height;
	int	width;

	height = -1;
	while (++height < map_inf->m_height)
	{
		width = -1;
		while (++width < map_inf->m_width)
		{
			if (height == 0 || height == map_inf->m_height - 1 \
				|| width == 0 || width == map_inf->m_width - 1)
			{
				if (!(map_inf->map[height][width] == ' ' \
					|| map_inf->map[height][width] == '1'))
					err_detect("Map is weird");
			}
			if (map_inf->map[height][width] == ' ')
				is_close(map_inf, height, width);
		}
	}
}

static void	is_close(t_map_inf *map_inf, int height, int width)
{
	const int	h_dir[4] = {1, -1, 0, 0};
	const int	w_dir[4] = {0, 0, 1, -1};
	int			k;

	k = -1;
	while (++k < 4)
	{
		if (0 <= height + h_dir[k] \
			&& height + h_dir[k] <= map_inf->m_height - 1 \
			&& 0 <= width + w_dir[k] \
			&& width + w_dir[k] <= map_inf->m_width - 1)
		{
			if (!(map_inf->map[height + h_dir[k]][width + w_dir[k]] == ' ' \
			|| map_inf->map[height + h_dir[k]][width + w_dir[k]] == '1'))
				err_detect("Map is unclosed");
		}
	}
}
