/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:47:08 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/11 17:46:36 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void free_splited_line(char **splited_line)
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

void    remove_nl(char *splited_line)
{
    int i;

    i = -1;
    while (splited_line[++i])
    {
        if (splited_line[i] == '\n')
            splited_line[i] = '\0';
    }
}
