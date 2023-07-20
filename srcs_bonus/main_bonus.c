/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:43 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 20:54:18 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "inspect_bonus.h"
#include "parsing_bonus.h"
#include "map_struct_bonus.h"
#include "drawing_bonus.h"

void	init_map_inf(t_map_inf *map_inf)
{
	map_inf->m_height = -1;
	map_inf->m_width = -1;
	map_inf->map = NULL;
	map_inf->player_direct = 'P';
	map_inf->player_loc_x = -1;
	map_inf->player_loc_y = -1;
	map_inf->identifier.f[0] = -1;
	map_inf->identifier.c[0] = -1;
	map_inf->identifier.n = NULL;
	map_inf->identifier.w = NULL;
	map_inf->identifier.e = NULL;
	map_inf->identifier.s = NULL;
}

int	main(int argc, char *argv[])
{
	int			file_fd;
	t_map_inf	map_inf;

	inspect_arg(argc, argv);
	file_fd = inspect_arg_file(argv[1]);
	init_map_inf(&map_inf);
	get_identifier(&(map_inf.identifier), file_fd);
	get_map_inf(&map_inf, file_fd);
	close(file_fd);
	draw_cub3d(&map_inf);
	return (0);
}
