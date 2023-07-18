/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:51:00 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/18 20:48:05 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "err_detect.h"
#include "map_struct.h"
#include "libft.h"
#include <stdlib.h>

static char	*map_copy_from_list(t_map_list *head, int width);

void	second_reading(t_map_inf *map_inf, t_map_list **head, t_map_list **tail)
{
	int	i;

	map_inf->map = (char **)malloc(sizeof(char *) * (map_inf->m_height + 1));
	if (map_inf->map == NULL)
		err_detect("Malloc Error");
	map_inf->map[map_inf->m_height] = NULL;
	i = -1;
	while (++i < map_inf->m_height)
	{
		map_inf->map[i] = map_copy_from_list(*head, map_inf->m_width);
		delete_list_front(head, tail);
	}
}

static char	*map_copy_from_list(t_map_list *head, int width)
{
	char	*map_element;
	int		length;

	map_element = (char *)malloc(sizeof(char) * (width + 1));
	if (map_element == NULL)
		err_detect("Malloc Error");
	map_element[width] = '\0';
	length = ft_strlcpy(map_element, head->map_element, width + 1);
	while (length < width)
	{
		map_element[length] = ' ';
		length++;
	}
	return (map_element);
}
