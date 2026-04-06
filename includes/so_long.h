/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/01 12:37:07 by mvelasqu         ###   ########.fr       */
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
	t_img	collect_1;
	t_img	collect_2;
	t_img	exit;
	t_img	enemy;
}			t_assets;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collect_count;
	int			move_count;
	int			anim_frame;
	int			anim_count;
	int			enemy_x;
	int			enemy_y;
	int			enemy_dir;
	t_assets	assets;
	t_map		*map_info;
}				t_game;

int		start_so_long(int argc, char **argv, t_map *map_info, t_unit *unit_info);
void	init_so_long(t_map *map_info, t_unit *unit_info);
void	map_free(t_map *map_info);
char	*map_error_str(int error);
void	map_print(char **map);
int		map_create(t_map *map_info, t_unit *unit_info, char **argv);
int		map_validation(char **argv, t_map *map_info, t_unit *unit_info)
int		map_validate_format(char **argv, t_map map_info)
int		map_validate_path(t_map *map_info, t_unit *unit_info);
int		map_dup(t_map *map_info);
int		start_game_so_long(t_game *game, t_map *map_info, t_unit *unit_info);
void	init_game(t_game *game);
int		game_load_assets_static(t_game *game);
int		game_load_assets_obj(t_game *game);
int		game_load_data(t_game *game, t_map *map_info, t_unit *unit_info);
void	game_cleanup(t_game *game);
int		game_print_key(int key, void *p);
int		game_handle_move_key(int key, t_game *game)
int		game_key_handler(int key, void *p);
int		game_key_close_x(void *p);
int		game_animate(void *p);
void	game_render_map(t_game *game);
void	game_print_move(t_game *game);
void	game_exit(t_game *game);
int		main(int argc, char **argv);

#endif