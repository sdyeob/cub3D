/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:30 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/12 20:57:28 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

void	get_identifier(t_identifier *identifier, int file_fd);
void	get_color(t_identifier *identifier, char *splited_line, int status);
void	get_map_inf(t_map_inf *map_inf, int file_fd);

#endif
