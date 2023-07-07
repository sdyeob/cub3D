/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:29:44 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/07 20:44:33 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "err.h"
#include "../../libft/libft.h"

void    inspect_arg(int argc, char *argv[]) {
    int arg_len;

    if (argc != 2) err("Argument is Wrong");
    arg_len = ft_strlen(argv[1]);
    if (arg_len <= 4) err("Argument is Wrong");
    if (!(argv[1][arg_len - 4] == '.' && argv[1][arg_len - 3] == 'c' \
        && argv[1][arg_len - 2] == 'u' && argv[1][arg_len - 1] == 'b'))
        err("Argument is Wrong");
}
