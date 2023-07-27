/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:46:26 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/27 21:35:16 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing_bonus.h"
#include "err_detect_bonus.h"
#include "parsing_struct_bonus.h"
#include "gnl.h"
#include "utils_bonus.h"

static int	line_check(t_map_inf *map_inf, char *line, int line_cnt);
static char	*skip_before_map_nl(int file_fd);
static void	skip_after_map_nl(int file_fd);

void	get_map_inf(t_map_inf *map_inf, int file_fd)
{
	t_map_list	*head;
	t_map_list	*tail;

	head = NULL;
	tail = NULL;
	reading_map_file(map_inf, file_fd, &head, &tail);
	copy_map_from_list(map_inf, &head, &tail);
	map_validity_check(map_inf);
}

void	reading_map_file(t_map_inf *map_inf, int file_fd, \
	t_map_list **head, t_map_list **tail)
{
	char	*line;
	int		line_cnt;
	int		length;

	line_cnt = 0;
	line = skip_before_map_nl(file_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			skip_after_map_nl(file_fd);
			break ;
		}
		length = line_check(map_inf, line, line_cnt);
		add_list_back(head, tail, line, length);
		if (map_inf->m_width < length)
			map_inf->m_width = length;
		line_cnt++;
		free(line);
		line = get_next_line(file_fd);
	}
	if (map_inf->player_loc_x == -1)
		err_detect("No Player");
	map_inf->m_height = line_cnt;
}

static char	*skip_before_map_nl(int file_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(file_fd);
		if (line)
		{
			if (line[0] == '\n')
				free(line);
			else
				return (line);
		}
		else
			err_detect("Map nonexist");
	}
}

static void	skip_after_map_nl(int file_fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(file_fd);
		if (line)
		{
			if (line[0] == '\n')
				free(line);
			else
			{
				free(line);
				err_detect("new line in map!");
			}
		}
		else
			return ;
	}
}

static int	line_check(t_map_inf *map_inf, char *line, int height)
{
	int	width;

	width = -1;
	remove_nl(line);
	while (line[++width])
	{
		if (line[width] == '1' || line[width] == '0' \
			|| line[width] == ' ' || line[width] == 'C')
			continue ;
		else if (line[width] == 'N' || line[width] == 'W' \
			|| line[width] == 'E' || line[width] == 'S')
		{
			if (map_inf->player_loc_x != -1)
				err_detect("Multi Player");
			map_inf->player_loc_x = width;
			map_inf->player_loc_y = height;
			map_inf->player_direct = line[width];
		}
		else
			err_detect("Map element");
	}
	return (width);
}
