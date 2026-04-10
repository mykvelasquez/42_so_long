/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 12:55:33 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/10 13:36:57 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_render_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->assets.space.img, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.wall.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
	{
		if (game->anim_frame == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->assets.collect_1.img, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->assets.collect_2.img, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.enemy.img, x * TILE_SIZE, y * TILE_SIZE);
	if (x == game->exit_x && y == game->exit_y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.exit.img, x * TILE_SIZE, y * TILE_SIZE);
	if (x == game->player_x && y == game->player_y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->assets.player.img, x * TILE_SIZE, y * TILE_SIZE);
}

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
			game_render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
