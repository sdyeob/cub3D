/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:15 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/10 21:02:54 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "err_detect.h"
#include "inspect.h"
#include "libft.h"
#include "gnl.h"
#include "struct.h"

int is_identifier(char *line)
{
    const char  *identifier[6] = {"NO", "WE", "EA", "SO", "F", "C"};
    int         i;

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

static void free_splited_line(char **splited_line)
{
    int i;

    if (splited_line)
    {
        i = -1;
        while (splited_line[++i])
            free(splited_line[i]);
        free(splited_line);
    }
}

int fill_identifier(t_identifier *identifier, char **splited_line, int status)
{
    if (status == 1 && !identifier->n)
        identifier->n = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]));
    else if (status == 2 && !identifier->w) 
        identifier->w = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]));
    else if (status == 3 && !identifier->e) 
        identifier->e = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]));
    else if (status == 4 && !identifier->s) 
        identifier->s = ft_substr(splited_line[1], 0, ft_strlen(splited_line[1]));
    else if (status == 5 && identifier->f[0] == -1)
        return(1);
        // identifier->f = get_color(splited_line, status);
    else if (status == 6 && identifier->c[0] == -1)
        return(1);
        // identifier->c = get_color(splited_line, status);
    else
        return (0);
    return (1);
}

char    **get_splited_line(int file_fd, int *status)
{
    char    *line;
    char    **splited_line;

    while (1)
    {
        line = get_next_line(file_fd);
        if (line)
        {
            if (line[0] == '\n')
            {
                free(line);
                continue;
            }
            splited_line = ft_split(line, ' ');
            if (inspect_splited_line(splited_line) != 2)
                err_detect("Identifier is Wrong");
            *status = is_identifier(splited_line[0]);
            if (*status == 0)
                err_detect("Identifier is Wrong");
            free(line);
            return (splited_line);
        }
        else
            err_detect("Few Map information");
    }
}

void    get_identifier(t_identifier *identifier, int file_fd)
{
    char    **splited_line;
    int     identifier_num;
    int     status;

    identifier_num = 0;
    while (1)
    {
        splited_line = get_splited_line(file_fd, &status);
        if (fill_identifier(identifier, splited_line, status))
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