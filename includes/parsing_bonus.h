/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:30 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:18 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "map_struct.h"

void	first_reading(t_map_inf *map_inf, int file_fd, \
	t_map_list **head, t_map_list **tail);
void	second_reading(t_map_inf *map_inf, \
	t_map_list **head, t_map_list **tail);
void	map_validity_check(t_map_inf *map_inf);
void	get_identifier(t_identifier *identifier, int file_fd);
void	get_color(t_identifier *identifier, char *splited_line, int status);
void	get_map_inf(t_map_inf *map_inf, int file_fd);
void	add_list_back(t_map_list **head, t_map_list **tail, \
	char *line, int length);
void	delete_list_front(t_map_list **head, t_map_list **tail);

#endif
