/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_load_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:36:34 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/16 09:37:27 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_load_assets_static(t_game *game)
{
	if (game_load_assets_check("assets/wall.xpm") == -1
		|| game_load_assets_check("assets/floor.xpm") == -1
		|| game_load_assets_check("assets/exit.xpm") == -1)
		return (-1);
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

int	game_load_assets_obj(t_game *game)
{
	if (game_load_assets_check("assets/player.xpm") == -1
		|| game_load_assets_check("assets/enemy.xpm") == -1)
		return (-1);
	game->assets.player.img = mlx_xpm_file_to_image(
			game->mlx, "assets/player.xpm",
			&game->assets.player.width, &game->assets.player.height);
	game->assets.enemy.img = mlx_xpm_file_to_image(
			game->mlx, "assets/enemy.xpm",
			&game->assets.enemy.width, &game->assets.enemy.height);
	if (!game->assets.player.img)
		return (ft_putendl_fd("Failed to load asset: player", 2), -1);
	if (!game->assets.enemy.img)
		return (ft_putendl_fd("Failed to load asset: enemy", 2), -1);
	return (0);
}

int	game_load_assets_collect(t_game *game)
{
	if (game_load_assets_check("assets/coin_1.xpm") == -1
		|| game_load_assets_check("assets/coin_2.xpm") == -1)
		return (-1);
	game->assets.collect_1.img = mlx_xpm_file_to_image(
			game->mlx, "assets/coin_1.xpm",
			&game->assets.collect_1.width, &game->assets.collect_1.height);
	game->assets.collect_2.img = mlx_xpm_file_to_image(
			game->mlx, "assets/coin_2.xpm",
			&game->assets.collect_2.width, &game->assets.collect_2.height);
	if (!game->assets.collect_1.img)
		return (ft_putendl_fd("Failed to load asset: collect 1", 2), -1);
	if (!game->assets.collect_2.img)
		return (ft_putendl_fd("Failed to load asset: collect 2", 2), -1);
	return (0);
}
