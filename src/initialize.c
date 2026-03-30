/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 11:43:09 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/24 13:46:46 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_map *map_info, t_unit *unit_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->map_str = NULL;
	map_info->map_str_arr = NULL;
	map_info->map_str_dup = NULL;
	unit_info->player = 'P';
	unit_info->exit = 'E';
	unit_info->wall = '1';
	unit_info->space = '0';
	unit_info->collectible = 'C';
	unit_info->enemy = 'X';
	unit_info->x_player = 0;
	unit_info->y_player = 0;
}

void	load_assets(t_game *game)
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
	game->assets.collectible.img = mlx_xpm_file_to_image(
		game->mlx, "assets/chest.xpm",
		&game->assets.collectible.width, &game->assets.collectible.height);
	game->assets.exit.img = mlx_xpm_file_to_image(
		game->mlx, "assets/exit.xpm",
		&game->assets.exit.width, &game->assets.exit.height);
	game->assets.enemy.img = mlx_xpm_file_to_image(
		game->mlx, "assets/enemy.xpm",
		&game->assets.enemy.width, &game->assets.enemy.height);
}