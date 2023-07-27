/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:43 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/27 22:11:14 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "parsing_struct.h"
#include "drawing.h"

int	main(int argc, char *argv[])
{
	t_map_inf	map_inf;

	map_inf = parsing_map_file(argc, argv);
	draw_cub3d(&map_inf);
	return (0);
}
