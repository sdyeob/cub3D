/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:47:20 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/21 15:41:02 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_splited_line(char **splited_line);
void	remove_nl(char *splited_line);
void	*mlx_xpm_file_to_image_s(void *xvar, char *file, \
	int *width, int *height);
#endif
