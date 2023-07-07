/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:43 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/07 20:10:16 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "err.h"

int main(int argc, char *argv[]) {
    char *str = argv[0];
    if (argc != 2) err("Argument is Wrong");

    printf("%s\n", str);
    return (0);
}
