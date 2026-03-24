/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 09:45:26 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <error.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct map
{
	int			fd;
	int			x;
	int			y;
	char		*map_str;
	char		**map_str_arr;
	char		**map_str_dup;
}				t_map;

typedef struct unit
{
	char		player;
	char		exit;
	char		collectible;
	char		wall;
	char		space;
}				t_unit;

void	init_so_long(t_map *map_info, t_unit *unit_info);
void	free_so_long(t_map *map_info);
void	print_map(char **map);
int		create_map(t_map *map_info, t_unit unit_info, char **argv);
int		map_validation(t_map *map_info, t_unit unit_info);
int		map_check_rectangle(t_map *map_info);
int		map_check_chars(t_map *map_info, t_unit unit_info);
int		map_check_enclosure(t_map *map_info, char c);
int		map_check_req_char(t_map *map_info, t_unit unit_info, char c);
int		map_dup(t_map *map_info);

#endif