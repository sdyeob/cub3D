/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_consts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:17:54 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/18 20:27:43 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_CONSTS_H
# define DRAWING_CONSTS_H

//Value, you can change
# define WIN_WIDTH 1024
# define WIN_HEIGHT 800

# define M_WIDTH 200
# define M_HEIGHT 200
# define M_BPP 0.05 //BLOCK_PER_PIXEL
# define M_PLAYER_RANGE 10
# define M_SEP 20
# define PLAYER_COLOR 0xFFFFFF
# define WALL_COLOR 0x000099
# define FLOOR_COLOR 0x0033FF
# define SPACE_COLOR 0x6699FF
# define OUT_OF_MAP_COLOR 0x00BFFF

# define PLANE_SIZE 0.67
# define VELOCITY 0.1
# define ANGLE_VELOCITY 0.1
# define MOUSE_ANGLE_RATIO 0.002

//fixed value
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

#endif