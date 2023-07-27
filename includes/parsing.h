/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:30 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/27 22:45:57 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "parsing_struct.h"

//parsing
t_map_inf	parsing_map_file(int argc, char *argv[]);

//map_init
t_map_inf	map_init(int argc, char *argv[]);

// parsing identifier
void		set_identifier(t_identifier *identifier, int file_fd);

// parsing color
void		set_color(t_identifier *identifier, char *splited_line, int status);

// parsing map
void		set_map_inf(t_map_inf *map_inf, int file_fd);
void		reading_map_file(t_map_inf *map_inf, int file_fd, \
	t_map_list **head, t_map_list **tail);
void		copy_map_from_list(t_map_inf *map_inf, \
	t_map_list **head, t_map_list **tail);

// map_validity
void		map_validity_check(t_map_inf *map_inf);

// map_list
void		add_list_back(t_map_list **head, t_map_list **tail, \
	char *line, int length);
void		delete_list_front(t_map_list **head, t_map_list **tail);

#endif
