/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:40:20 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/21 20:13:55 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSPECT_BONUS_H
# define INSPECT_BONUS_H

void	inspect_arg(int argc, char *argv[]);
int		inspect_arg_file(const char *filename);
int		get_splited_line_height(char **splited_line);

#endif
