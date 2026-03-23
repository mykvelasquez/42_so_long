/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/20 12:30:37 by mvelasqu         ###   ########.fr       */
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

typedef struct map {
    int         fd;
    int         x;
    int         y;
    char        *map_str;
    char        **map_arr;
	char		**map_dup;
}               map_data;

typedef struct unit {
	char		player;
	char		exit;
	char		collectible;
	char		wall;
	char		space;
}				map_unit;

int		map_check_rectangle(map_data *mapInfo);
int		map_check_chars(map_data *mapInfo, map_unit unitInfo);
int		map_check_enclosure(map_data *mapInfo, char c);
int		map_check_req_char(map_data *mapInfo, map_unit unitInfo, char c);
void	**map_dup(map_data *mapInfo);
int		create_map(map_data *mapInfo, map_unit unitInfo, char **argv);
int		map_validation(map_data *mapInfo, map_unit unitInfo);
int		main(int argc, char **argv);

#endif