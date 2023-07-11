/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:43 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/11 20:17:37 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "err.h"
#include "inspect.h"
#include "parsing.h"
#include "struct.h"

#include <stdio.h>

#include <stdlib.h>

void    init_map_inf(t_map_inf *map_inf)
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

void    free_map_inf(t_map_inf *map_inf)
{
    int i;

    if (map_inf->identifier.n)
        free(map_inf->identifier.n);
    if (map_inf->identifier.w)
        free(map_inf->identifier.w);
    if (map_inf->identifier.e)
        free(map_inf->identifier.e);
    if (map_inf->identifier.s)
        free(map_inf->identifier.s);
    if (map_inf->map)
    {
        i = -1;
        while (map_inf->map[++i])
            free(map_inf->map[i]);
        free(map_inf->map);
    }
}

int main(int argc, char *argv[]) {
    int             file_fd;
       t_map_inf       map_inf;

    inspect_arg(argc, argv);
    file_fd = inspect_arg_file(argv[1]);
    init_map_inf(&map_inf);
    get_identifier(&(map_inf.identifier), file_fd);
    // map_inf = get_map_inf();
    draw_cub3d(&map_inf);
    close(file_fd);
    free_map_inf(&map_inf);
    return (0);
}
