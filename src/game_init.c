/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:21:03 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 13:55:15 by mvelasqu         ###   ########.fr       */
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
	game->assets.collect.img = NULL;
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
}

void	game_load_assets(t_game *game)
{
	game->assets.player.img = mlx_xpm_file_to_image(
		game->mlx, "assets/player.xpm",
		&game->assets.player.width, &game->assets.player.height);
	game->assets.wall.img = mlx_xpm_file_to_image(
		game->mlx, "assets/wall.xpm",
		&game->assets.wall.width, &game->assets.wall.height);
	game->assets.space.img = mlx_xpm_file_to_image(
		game->mlx, "assets/floor.xpm",
		&game->assets.space.width, &game->assets.space.height);
	game->assets.collect.img = mlx_xpm_file_to_image(
		game->mlx, "assets/chest.xpm",
		&game->assets.collect.width, &game->assets.collect.height);
	game->assets.exit.img = mlx_xpm_file_to_image(
		game->mlx, "assets/exit.xpm",
		&game->assets.exit.width, &game->assets.exit.height);
	game->assets.enemy.img = mlx_xpm_file_to_image(
		game->mlx, "assets/enemy.xpm",
		&game->assets.enemy.width, &game->assets.enemy.height);
}

int		game_load_data(t_game *game, t_map *map_info, t_unit *unit_info)
{
	game->map = map_info->map_str_dup;
	game->map_width = map_info->x;
	game->map_height = map_info->y;
	game->player_x = unit_info->x_player;
	game->player_y = unit_info->y_player;
	game->exit_x = unit_info->x_exit;
	game->exit_y = unit_info->y_exit;
	game->collect_count = unit_info->collect_count;
	return (0);
}

