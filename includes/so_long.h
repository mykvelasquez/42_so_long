/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 13:34:39 by mvelasqu         ###   ########.fr       */
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
	int			y_player;
	int			x_player;
}				t_unit;

void	init_so_long(t_map *map_info, t_unit *unit_info);
void	free_so_long(t_map *map_info);
char	*ft_map_error(int error);
void	print_map(char **map);
int		create_map(t_map *map_info, t_unit unit_info, char **argv);
int		map_validation(t_map *map_info, t_unit unit_info);
int		map_check_rectangle(t_map *map_info);
int		map_check_chars(char **map_arr, t_unit unit_info);
int		map_check_enclosure(t_map *map_info, char c);
int		map_check_req_char(char **map_arr, t_unit unit_info, char c);
int		map_check_end_new_line(t_map *map_info);
int		map_check_file_format(char **argv);
int		map_check_find_path(t_map *map_info, t_unit *unit_info);
int		map_dup(t_map *map_info);
int		main(int argc, char **argv);

#endif