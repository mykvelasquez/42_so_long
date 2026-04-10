/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 12:32:05 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/10 13:37:01 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init_enemy(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'X')
			{
				game->enemy_x = x;
				game->enemy_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	game_move_enemy(t_game *game)
{
	int	next_x;

	if (game->enemy_x < 0 || game->enemy_y < 0)
		return ;
	next_x = game->enemy_x + game->enemy_dir;
	if (next_x < 0 || next_x >= game->map_width
		|| game->map[game->enemy_y][next_x] == '1'
		|| game->map[game->enemy_y][next_x] == 'C'
		|| game->map[game->enemy_y][next_x] == 'E')
	{
		game->enemy_dir *= -1;
		next_x = game->enemy_x + game->enemy_dir;
		if (next_x < 0 || next_x >= game->map_width
			|| game->map[game->enemy_y][next_x] == '1'
			|| game->map[game->enemy_y][next_x] == 'C'
			|| game->map[game->enemy_y][next_x] == 'E')
			return ;
	}
	if (game->player_x == next_x && game->player_y == game->enemy_y)
		game_exit(game);
	game->map[game->enemy_y][game->enemy_x] = '0';
	game->enemy_x = next_x;
	game->map[game->enemy_y][game->enemy_x] = 'X';
}
