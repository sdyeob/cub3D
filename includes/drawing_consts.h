/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_consts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:17:54 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:04:56 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_CONSTS_H
# define DRAWING_CONSTS_H

//Value, you can change
# define W_WIDTH 1024
# define W_HEIGHT 800

# define M_WIDTH 200
# define M_HEIGHT 200
# define M_BPP 0.05 //BLOCK_PER_PIXEL
# define M_PLAYER_RANGE 10
# define M_SEP 20
# define DOOR_COLOR 0xCC6633
# define PLAYER_COLOR 0xFFFFFF
# define WALL_COLOR 0x000099
# define FLOOR_COLOR 0x0033FF
# define SPACE_COLOR 0x6699FF
# define OUT_OF_MAP_COLOR 0x00BFFF

# define BLOCK_PER_WIN 0.5
# define PLANE_SIZE 1.4
# define VELOCITY 0.06
# define ANGLE_VELOCITY 0.1
# define MOUSE_ANGLE_RATIO 0.002

# define DOOR_SEARCH_RANGE 0.9
# define DOOR_MIN_DEGREE 0
# define DOOR_MAX_DEGREE 35
# define DOOR_XPM_PATH "test_files/door.xpm"

//fixed value
# define KEY_SPACE 49
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

#endif