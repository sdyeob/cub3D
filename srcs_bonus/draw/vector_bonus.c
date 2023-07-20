/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:24 by seunghoy          #+#    #+#             */
/*   Updated: 2023/07/20 20:22:35 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/drawing_struct.h"
#include "../../includes/drawing_consts.h"

t_vec_d	get_plane_vec(t_vec_d dir)
{
	t_vec_d	plane;

	plane.x = PLANE_SIZE * dir.y;
	plane.y = PLANE_SIZE * (-dir.x);
	return (plane);
}

t_vec_d	rotate_vec(t_vec_d dir, double angle)
{
	t_vec_d	ro;

	ro.x = cos(angle) * dir.x + sin(angle) * dir.y;
	ro.y = -sin(angle) * dir.x + cos(angle) * dir.y;
	return (ro);
}

t_vec_d	add_vec(t_vec_d a, t_vec_d b)
{
	t_vec_d	add;

	add.x = a.x + b.x;
	add.y = a.y + b.y;
	return (add);
}

t_vec_d	mult_vec(double scalar, t_vec_d vec)
{
	t_vec_d	sm;

	sm.x = scalar * vec.x;
	sm.y = scalar * vec.y;
	return (sm);
}

t_vec_i	init_vec_i(int x, int y)
{
	t_vec_i	vec_i;

	vec_i.x = x;
	vec_i.y = y;
	return (vec_i);
}