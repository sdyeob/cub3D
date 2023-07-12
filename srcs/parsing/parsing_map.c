/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:46:26 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/12 21:14:37 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "err_detect.h"
#include "struct.h"
#include "gnl.h"
#include "utils.h"

static void	first_reading(t_map_inf *map_inf, int file_fd);
static int	line_check(t_map_inf *map_inf, char *line, int line_cnt);

void	get_map_inf(t_map_inf *map_inf, int file_fd)
{
	first_reading(map_inf, file_fd);
	// second_reading(map_inf, file_fd);
}

static int	line_check(t_map_inf *map_inf, char *line, int line_cnt)
{
	int i;

	i = -1;
	remove_nl(line);
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			continue ;
		else if (line[i] == 'N' || line[i] == 'W' \
			|| line[i] == 'E' || line[i] == 'S')
		{
			if (map_inf->player_loc_x != -1)
				err_detect("Error : Multi Player");
			map_inf->player_loc_x = i;
			map_inf->player_loc_y = line_cnt;
			map_inf->player_direct = line[i];
		}
		else
			err_detect("Error : Map element");
	}
	return (i);
}

static void	first_reading(t_map_inf *map_inf, int file_fd)
{
	char	*line;
	int		is_map;
	int		line_cnt;
	int		length;

	is_map = 0;
	line_cnt = 0;
	while (1)
	{
		line = get_next_line(file_fd);
		if (line)
		{
			if (line[0] == '\n')
			{
				if (is_map == 1)
					err_detect("Map Error : new line in map");
				free(line);
				continue ;
			}
			is_map = 1;
			length = line_check(map_inf, line, line_cnt);
			// add list to back;
			if (map_inf->m_width < length)
				map_inf->m_width = length;
			line_cnt++;
			free(line);
		}
		else
			break ;
	}
	if (map_inf->m_width == -1)
		err_detect("Error : Map nonexist");
	if (map_inf->player_loc_x == -1)
		err_detect("Error : No Player");
	map_inf->m_height = line_cnt;
}

// void	second_reading(t_map_inf *map_inf, int file_fd)
// {
	
// }
