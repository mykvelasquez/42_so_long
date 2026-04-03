/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/01 12:50:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	game_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->assets.space.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.wall.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.collect.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.enemy.img, x * TILE_SIZE, y * TILE_SIZE);
			if (x == game->exit_x && y == game->exit_y)
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.exit.img, x * TILE_SIZE, y * TILE_SIZE);
			if (x == game->player_x && y == game->player_y)
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.player.img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map_info;
	t_unit	unit_info;
	t_game	game;
	// Initialize map structure
	if (start_so_long(argc, argv, &map_info, &unit_info) == -1)
		return (map_free(&map_info), 1);
	// Initialize game structure
	if (start_game_so_long(&game, &map_info, &unit_info) == -1)
		return (map_free(&map_info), 1);
	game_render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, game_key_handler, &game);
	mlx_hook(game.win, 17, 0, game_key_close_x, &game);
	mlx_loop(game.mlx);
	game_exit(&game);
	return (0);
}