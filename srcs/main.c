/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:43 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/10 16:11:26 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "err.h"
#include "inspect.h"

int main(int argc, char *argv[]) {
    int file_fd;

    inspect_arg(argc, argv);
    file_fd = inspect_arg_file(argv[1]);
    
    close(file_fd);
    return (0);
}
