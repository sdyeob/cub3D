/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:36:58 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 20:22:40 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "map_struct.h"
#include "err_detect.h"

void	add_list_back(t_map_list **head, t_map_list **tail, \
	char *line, int length)
{
	t_map_list	*new;

	new = (t_map_list *)malloc(sizeof(t_map_list) * 1);
	if (new == NULL)
		err_detect("Malloc Error");
	new->map_element = ft_substr(line, 0, length);
	if (new->map_element == NULL)
		err_detect("Malloc Error");
	new->next = NULL;
	if (*tail == NULL)
	{
		*tail = new;
		*head = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
}

void	delete_list_front(t_map_list **head, t_map_list **tail)
{
	t_map_list	*del;

	if (*head == NULL)
		return ;
	if (*head == *tail)
	{
		del = *head;
		*tail = NULL;
		*head = NULL;
	}
	else
	{
		del = *head;
		*head = (*head)->next;
	}
	free(del->map_element);
	free(del);
}
