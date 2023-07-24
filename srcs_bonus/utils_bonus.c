/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:47:08 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/24 21:18:52 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "err_detect_bonus.h"

void	free_splited_line(char **splited_line)
{
	int	i;

	if (splited_line)
	{
		i = -1;
		while (splited_line[++i])
			free(splited_line[i]);
		free(splited_line);
	}
}

void	remove_nl(char *splited_line)
{
	int	i;

	i = -1;
	while (splited_line[++i])
	{
		if (splited_line[i] == '\n')
			splited_line[i] = '\0';
	}
}

void	*mlx_xpm_file_to_image_s(void *xvar, char *file, \
	int *width, int *height)
{
	void	*re;

	re = mlx_xpm_file_to_image(xvar, file, width, height);
	if (re == NULL)
		err_detect("Non exist file");
	return (re);
}

int	get_splited_line_height(char **splited_line)
{
	int	i;

	i = -1;
	while (splited_line[++i])
		;
	return (i);
}
