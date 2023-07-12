/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:13 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/12 17:56:20 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "err_detect.h"
#include "inspect.h"
#include "libft.h"
#include "gnl.h"
#include "struct.h"
#include "utils.h"
#include "parsing.h"

static int	is_identifier(char *line);
static int	fill_identifier(t_identifier *identifier, \
	char *splited_line, int status);
static char	**get_splited_line(int file_fd, int *status);

void	get_identifier(t_identifier *identifier, int file_fd)
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
		err_detect("Error : Few or More identifier");

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
	return (0);
}

static void	inspect_xpm_extension(char *splited_line)
{
	int	length;

	length = ft_strlen(splited_line);
	if (length < 5 || !(splited_line[length - 4] == '.' \
		&& splited_line[length - 3] == 'x' \
		&& splited_line[length - 2] == 'p' \
		&& splited_line[length - 1] == 'm'))
		err_detect("Error : Information");
}

static int	fill_identifier(t_identifier *identifier, \
	char *splited_line, int status)
{
	remove_nl(splited_line);
	if (1 <= status && status <= 4)
		inspect_xpm_extension(splited_line);
	if (status == 1 && !identifier->n)
		identifier->n = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == 2 && !identifier->w)
		identifier->w = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == 3 && !identifier->e)
		identifier->e = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == 4 && !identifier->s)
		identifier->s = ft_substr(splited_line, 0, ft_strlen(splited_line));
	else if (status == 5 && identifier->f[0] == -1)
		get_color(identifier, splited_line, status);
	else if (status == 6 && identifier->c[0] == -1)
		get_color(identifier, splited_line, status);
	else
		return (0);
	return (1);
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
			if (line[0] == '\n')
			{
				free(line);
				continue ;
			}
			splited_line = ft_split(line, ' ');
			if (inspect_splited_line(splited_line) != 2)
				err_detect("Error : Identifier");
			*status = is_identifier(splited_line[0]);
			if (*status == 0)
				err_detect("Error : Identifier Or Information");
			free(line);
			return (splited_line);
		}
		else
			err_detect("Error : Few Map information");
	}
}
