/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:35:27 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/12 20:47:48 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "drawing_struct.h"

//render_frame.c
int		render_frame(t_draw *draw);

//vector.c
t_vec_d	get_plane_vec(t_vec_d dir);
t_vec_d	rotate_vec(t_vec_d dir, double angle);
t_vec_d	add_vec(t_vec_d a, t_vec_d b);
t_vec_d	mult_vec(double scalar, t_vec_d vec);

#endif