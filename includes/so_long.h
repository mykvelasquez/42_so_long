/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 12:07:44 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include <stdlib.h>
# include <error.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>




#define TILE_SIZE 32

typedef struct s_map
{
	int			fd;
	int			x;
	int			y;
	char		*map_str;
	char		**map_str_arr;
	char		**map_str_dup;
}				t_map;

typedef struct s_unit
{
	char		player;
	char		exit;
	char		collectible;
	char		wall;
	char		space;
	char		enemy;
	int			y_player;
	int			x_player;
	int			y_exit;
	int			x_exit;
	int			collect_count;
}				t_unit;

typedef struct s_img
{
	void	*img;
	int 	height;
	int		width;
}			t_img;

typedef struct s_assets
{
	t_img	player;
	t_img	wall;
	t_img	space;
	t_img	collect;
	t_img	exit;
	t_img	enemy;
}			t_assets;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_assets	assets;
}				t_game;

void	init_so_long(t_map *map_info, t_unit *unit_info);
void	load_assets(t_game *game);
void	free_so_long(t_map *map_info);
char	*ft_map_error(int error);
void	print_map(char **map);
void	get_map_dimension(t_map *map_info);
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