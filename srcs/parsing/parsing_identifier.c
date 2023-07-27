/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:13 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/27 22:46:40 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "err_detect.h"
#include "libft.h"
#include "gnl.h"
#include "parsing_struct.h"
#include "utils.h"
#include "parsing.h"

static char	**get_splited_line(int file_fd, int *status);
static int	is_identifier(char *line);
static int	fill_identifier(t_identifier *identifier, \
	char *splited_line, int status);
static void	inspect_xpm_extension(char *splited_line);

void	set_identifier(t_identifier *identifier, int file_fd)
{
	char	**splited_line;
	int		identifier_num;
	int		status;

	identifier_num = 0;
	while (1)
	{
		splited_line = get_splited_line(file_fd, &status);
		if (fill_identifier(identifier, splited_line[1], status))
		{
			if (++identifier_num == 6)
				break ;
		}
		else
			break ;
		free_splited_line(splited_line);
	}
	free_splited_line(splited_line);
	if (identifier_num != 6)
		err_detect("Few or More identifier");
}

static char	**get_splited_line(int file_fd, int *status)
{
	char	*line;
	char	**splited_line;

	while (1)
	{
		line = get_next_line(file_fd);
		if (line)
		{
			if (line[0] != '\n')
			{
				remove_nl(line);
				splited_line = ft_split(line, ' ');
				if (get_splited_line_height(splited_line) != 2)
					err_detect("Identifier");
				*status = is_identifier(splited_line[0]);
				if (*status == NOT_IDENTIFIER)
					err_detect("Identifier Or Information");
				free(line);
				return (splited_line);
			}
			free(line);
		}
		else
			err_detect("Few Map information");
	}
}

static int	is_identifier(char *line)
{
	const char	*identifier[6] = {"NO", "WE", "EA", "SO", "F", "C"};
	int			i;

	if (line == NULL)
		return (0);
	i = -1;
	while (++i < 6)
	{
		if (ft_strncmp(line, identifier[i], ft_strlen(identifier[i]) + 1) == 0)
			return (i + 1);
	}
	return (NOT_IDENTIFIER);
}

static int	fill_identifier(t_identifier *identifier, \
	char *splited_line, int status)
{
	if (NORTH <= status && status <= SOUTH)
		inspect_xpm_extension(splited_line);
	if (status == NORTH && !identifier->n)
		identifier->n = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == WEST && !identifier->w)
		identifier->w = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == EAST && !identifier->e)
		identifier->e = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == SOUTH && !identifier->s)
		identifier->s = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == FLOOR && identifier->f[0] == -1)
		set_color(identifier, splited_line, status);
	else if (status == CEIL && identifier->c[0] == -1)
		set_color(identifier, splited_line, status);
	else
		return (0);
	return (1);
}

static void	inspect_xpm_extension(char *splited_line)
{
	int	length;

	length = ft_strlen(splited_line);
	if (length <= 4)
		err_detect("Information");
	if (!(splited_line[length - 4] == '.' \
		&& splited_line[length - 3] == 'x' \
		&& splited_line[length - 2] == 'p' \
		&& splited_line[length - 1] == 'm'))
		err_detect("Information");
	if (splited_line[length - 5] == '/')
		err_detect("Argument is Wrong");
}
