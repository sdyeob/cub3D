/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindong-yeob <sindong-yeob@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:14:21 by sindong-yeo       #+#    #+#             */
/*   Updated: 2023/07/27 22:14:41 by sindong-yeo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_STRUCT_H
# define PARSING_STRUCT_H

typedef struct s_map_list	t_map_list;

enum	e_identifier
{
	NOT_IDENTIFIER,
	NORTH,
	WEST,
	EAST,
	SOUTH,
	FLOOR,
	CEIL
};

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
