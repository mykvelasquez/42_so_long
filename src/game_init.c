/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:21:03 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/06 12:36:33 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->win = NULL;
	game->mlx = NULL;
	game->assets.player.img = NULL;
	game->assets.wall.img = NULL;
	game->assets.space.img = NULL;
	game->assets.collect_1.img = NULL;
	game->assets.collect_2.img = NULL;
	game->assets.exit.img = NULL;
	game->assets.enemy.img = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collect_count = 0;
	game->move_count = 0;
	game->anim_frame = 0;
	game->anim_count = 0;
	game->enemy_x = -1;
	game->enemy_y = -1;
	game->enemy_dir = 1;
}

int		game_load_assets_static(t_game *game)
{
	game->assets.wall.img = mlx_xpm_file_to_image(
		game->mlx, "assets/wall.xpm",
		&game->assets.wall.width, &game->assets.wall.height);
	game->assets.space.img = mlx_xpm_file_to_image(
		game->mlx, "assets/floor.xpm",
		&game->assets.space.width, &game->assets.space.height);
	game->assets.exit.img = mlx_xpm_file_to_image(
		game->mlx, "assets/exit.xpm",
		&game->assets.exit.width, &game->assets.exit.height);
	if (!game->assets.wall.img)
		return (ft_putendl_fd("Failed to load asset: wall", 2), -1);
	if (!game->assets.exit.img)
		return (ft_putendl_fd("Failed to load asset: exit", 2), -1);
	if (!game->assets.space.img)
		return (ft_putendl_fd("Failed to load asset: space", 2), -1);
	return (0);
}

int		game_load_assets_obj(t_game *game)
{
	game->assets.collect_1.img = mlx_xpm_file_to_image(
		game->mlx, "assets/coin_1.xpm",
		&game->assets.collect_1.width, &game->assets.collect_1.height);
	game->assets.collect_2.img = mlx_xpm_file_to_image(
		game->mlx, "assets/coin_2.xpm",
		&game->assets.collect_2.width, &game->assets.collect_2.height);
	game->assets.player.img = mlx_xpm_file_to_image(
		game->mlx, "assets/player.xpm",
		&game->assets.player.width, &game->assets.player.height);
	game->assets.enemy.img = mlx_xpm_file_to_image(
		game->mlx, "assets/enemy.xpm",
		&game->assets.enemy.width, &game->assets.enemy.height);
	if (!game->assets.collect_1.img)
		return (ft_putendl_fd("Failed to load asset: collect 1", 2), -1);
	if (!game->assets.collect_2.img)
		return (ft_putendl_fd("Failed to load asset: collect 2", 2), -1);
	if (!game->assets.player.img)
		return (ft_putendl_fd("Failed to load asset: player", 2), -1);
	if (!game->assets.enemy.img)
		return (ft_putendl_fd("Failed to load asset: enemy", 2), -1);
	return (0);
}

int		game_load_data(t_game *game, t_map *map_info, t_unit *unit_info)
{
	game->map = map_info->map_str_arr;
	game->map_width = map_info->x;
	game->map_height = map_info->y;
	game->map_info = map_info;
	game->player_x = unit_info->x_player;
	game->player_y = unit_info->y_player;
	game->exit_x = unit_info->x_exit;
	game->exit_y = unit_info->y_exit;
	game->collect_count = unit_info->collect_count;
	return (0);
}

int		start_game_so_long(t_game *game, t_map *map_info, t_unit *unit_info)
{
	init_game(game);
	game_load_data(game, map_info, unit_info);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (game_cleanup(game), -1);
	game->win = mlx_new_window(game->mlx,
			game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE,
			"so_long");
	if (!game->win)
		return (game_cleanup(game), -1);
	if (game_load_assets_obj(game) == -1)
		return (game_cleanup(game), -1);
	if (game_load_assets_static(game) == -1)
		return (game_cleanup(game), -1);
	game_init_enemy(game);
	return (0);
}