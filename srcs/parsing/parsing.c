/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:47:32 by sindong-yeo       #+#    #+#             */
/*   Updated: 2023/07/27 21:57:15 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "parsing_struct.h"
#include "parsing.h"
#include "err_detect.h"
#include "libft.h"

static void			inspect_arg(int argc, char *argv[]);
static int			inspect_arg_file(const char *filename);
static t_map_inf	init_map_inf(void);

t_map_inf	parsing_map_file(int argc, char *argv[])
{
	t_map_inf	map_inf;
	int			fildes;

	inspect_arg(argc, argv);
	fildes = inspect_arg_file(argv[1]);
	map_inf = init_map_inf();
	get_identifier(&(map_inf.identifier), fildes);
	get_map_inf(&map_inf, fildes);
	close(fildes);
	return (map_inf);
}

static void	inspect_arg(int argc, char *argv[])
{
	int	arg_len;

	if (argc != 2)
		err_detect("Argument is Wrong");
	arg_len = ft_strlen(argv[1]);
	if (arg_len <= 4)
		err_detect("Argument is Wrong");
	if (!(argv[1][arg_len - 4] == '.' && argv[1][arg_len - 3] == 'c' \
		&& argv[1][arg_len - 2] == 'u' && argv[1][arg_len - 1] == 'b'))
		err_detect("Argument is Wrong");
	if (argv[1][arg_len - 5] == '/')
		err_detect("Argument is Wrong");
}

static int	inspect_arg_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		err_detect("Argument Error");
	return (fd);
}

static t_map_inf	init_map_inf(void)
{
	t_map_inf	map_inf;

	map_inf.m_height = -1;
	map_inf.m_width = -1;
	map_inf.map = NULL;
	map_inf.player_direct = 'P';
	map_inf.player_loc_x = -1;
	map_inf.player_loc_y = -1;
	map_inf.identifier.f[0] = -1;
	map_inf.identifier.c[0] = -1;
	map_inf.identifier.n = NULL;
	map_inf.identifier.w = NULL;
	map_inf.identifier.e = NULL;
	map_inf.identifier.s = NULL;
	return (map_inf);
}
