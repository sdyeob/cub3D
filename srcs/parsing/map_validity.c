/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:18:22 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 16:45:37 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_struct.h"
#include "err_detect.h"

static void	is_close(t_map_inf *map_inf, int i, int j);

void	map_validity_check(t_map_inf *map_inf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_inf->m_height)
	{
		j = -1;
		while (++j < map_inf->m_width)
		{
			if (i == 0 || i == map_inf->m_height - 1 \
				|| j == 0 || j == map_inf->m_width - 1)
			{
				if (!(map_inf->map[i][j] == ' ' || map_inf->map[i][j] == '1'))
					err_detect("Map is weird");
			}
			if (map_inf->map[i][j] == ' ')
				is_close(map_inf, i, j);
		}
	}
}

static void	is_close(t_map_inf *map_inf, int i, int j)
{
	const int	i_direct[4] = {1, -1, 0, 0};
	const int	j_direct[4] = {0, 0, 1, -1};
	int			k;

	k = -1;
	while (++k < 4)
	{
		if (0 <= i + i_direct[k] && i + i_direct[k] <= map_inf->m_height - 1 \
			&& 0 <= j + j_direct[k] && j + j_direct[k] <= map_inf->m_width - 1)
		{
			if (!(map_inf->map[i + i_direct[k]][j + j_direct[k]] == ' ' \
			|| map_inf->map[i + i_direct[k]][j + j_direct[k]] == '1'))
				err_detect("Map is unclosed");
		}
	}
}
