/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:59:02 by dongyshi          #+#    #+#             */
/*   Updated: 2023/07/16 21:02:18 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"
#include "drawing_struct.h"

void	render_minimap(t_img *img)
{
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++)
			my_mlx_pixel_put(img, 20 + j, 20 + i, 255);
	}
}
