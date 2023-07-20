/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:40:20 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/20 20:22:20 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSPECT_H
# define INSPECT_H

void	inspect_arg(int argc, char *argv[]);
int		inspect_arg_file(const char *filename);
int		inspect_splited_line(char **splited_line);

#endif
