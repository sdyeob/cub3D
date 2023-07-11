/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:40:20 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/11 22:20:18 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSPECT_H
# define INSPECT_H

void	inspect_arg(int argc, char *argv[]);
int		inspect_arg_file(const char *filename);
int		inspect_splited_line(char **splited_line);

#endif
