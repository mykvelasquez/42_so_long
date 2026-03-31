/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 13:59:02 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




void	render_map(t_game *game)
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
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.player.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.collect.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.exit.img, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'M')
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets.enemy.img, x * TILE_SIZE, y * TILE_SIZE);
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
	if (start_so_long(argc, argv, &map_info, unit_info) == -1)
		return (1);
	// Initialize game structure

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	// Initialize window
	game.win = mlx_new_window(game.mlx,
			game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE,
			"mlx test");
	if (!game.win)
		return (1);
	load_assets(&game);
	render_map(&game);
	printf("%d\n", mlx_hook(game.win, 2, 1L << 0, game_key_close_esc, &game));
	printf("%d\n", mlx_hook(game.win, 17, 0, game_key_close_x, &game));
	mlx_loop(game.mlx);
	map_free(&map_info);
	return (0);
}
