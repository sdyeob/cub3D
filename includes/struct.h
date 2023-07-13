/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyshi <dongyshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:14:21 by sindong-yeo       #+#    #+#             */
/*   Updated: 2023/07/13 14:40:39 by dongyshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map_list t_map_list;

struct s_map_list
{
	char		*map_element;
	t_map_list	*next;
};

typedef struct s_identifier {
	char	*n;
	char	*w;
	char	*e;
	char	*s;
	int		f[3];
	int		c[3];
}	t_identifier;

typedef struct s_map_inf {
	t_identifier	identifier;
	char			**map;
	int				m_width;
	int				m_height;
	int				player_loc_x;
	int				player_loc_y;
	char			player_direct;
}	t_map_inf;

#endif
