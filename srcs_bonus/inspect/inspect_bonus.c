/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:29:44 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 20:53:06 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "err_detect_bonus.h"
#include "libft.h"

void	inspect_arg(int argc, char *argv[])
{
	int	arg_len;

	if (argc != 2)
		err_detect("Argument is Wrong");
	arg_len = ft_strlen(argv[1]);
	if (arg_len <= 4)
		err_detect("Argument is Wrong");
	if (!(argv[1][arg_len - 4] == '.' && argv[1][arg_len - 3] == 'c' \
		&& argv[1][arg_len - 2] == 'u' && argv[1][arg_len - 1] == 'b'))
		err_detect("Argument is Wrong");
}

int	inspect_arg_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		err_detect("Filename is Wrong");
	return (fd);
}

int	inspect_splited_line(char **splited_line)
{
	int	i;

	i = -1;
	while (splited_line[++i])
		;
	return (i);
}
