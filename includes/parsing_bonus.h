/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:30 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/21 20:24:53 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "map_struct_bonus.h"

void	reading_map_file(t_map_inf *map_inf, int file_fd, \
	t_map_list **head, t_map_list **tail);
void	copy_map_from_list(t_map_inf *map_inf, \
	t_map_list **head, t_map_list **tail);
void	map_validity_check(t_map_inf *map_inf);
void	get_identifier(t_identifier *identifier, int file_fd);
void	get_color(t_identifier *identifier, char *splited_line, int status);
void	get_map_inf(t_map_inf *map_inf, int file_fd);
void	add_list_back(t_map_list **head, t_map_list **tail, \
	char *line, int length);
void	delete_list_front(t_map_list **head, t_map_list **tail);

#endif
