/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_detect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:58:03 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/10 20:39:48 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void    err_detect(const char *str) {
    write(2, "Error\n", 7);
    write(2, str, ft_strlen(str));
    write(2, "\n", 1);
    exit(1);
}
