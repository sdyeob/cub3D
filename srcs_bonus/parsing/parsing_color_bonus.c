/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:45:32 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/27 22:12:45 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_detect_bonus.h"
#include "parsing_struct_bonus.h"
#include "libft.h"

static int	get_color_inf(char *splited_line, int idx);
static void	set_color_inf(t_identifier *identifier, \
	char *splited_line, int status);

void	get_color(t_identifier *identifier, char *splited_line, int status)
{
	int	i;
	int	comma_cnt;
	int	length;

	i = -1;
	comma_cnt = 0;
	length = 0;
	while (splited_line[++i])
	{
		if (ft_isdigit(splited_line[i]))
			length++;
		else if (splited_line[i] == ',')
		{
			if (length == 0 || length > 3)
				err_detect("Information is Wrong");
			length = 0;
			comma_cnt++;
		}
		else
			err_detect("Information is Wrong");
	}
	if (comma_cnt != 2 || length == 0 || length > 3)
		err_detect("Information is Wrong");
	set_color_inf(identifier, splited_line, status);
}

static void	set_color_inf(t_identifier *identifier, \
	char *splited_line, int status)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (status == FLOOR)
			identifier->f[i] = get_color_inf(splited_line, i);
		else if (status == CEIL)
			identifier->c[i] = get_color_inf(splited_line, i);
	}
}

static int	get_color_inf(char *splited_line, int idx)
{
	int	i;
	int	comma_cnt;
	int	return_val;

	i = -1;
	comma_cnt = 0;
	return_val = 0;
	while (splited_line[++i])
	{
		if (idx == comma_cnt)
		{
			while (splited_line[i] && splited_line[i] != ',')
			{
				return_val = (return_val * 10) + splited_line[i] - '0';
				++i;
			}
			break ;
		}
		if (splited_line[i] == ',')
			comma_cnt++;
	}
	if (return_val > 255)
		err_detect("Information is Wrong");
	return (return_val);
}
