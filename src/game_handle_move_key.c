/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:29:40 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/01 12:58:42 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	game_collect_item(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'C')
	{
		game->collect_count -= 1;
		game->map[y][x] = '0';
	}
}

static void	game_check_tile(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'X')
		game_exit(game);
	if (game->map[y][x] == 'E' && game->collect_count == 0)
		game_exit(game);
	game_collect_item(game, y, x);
}

static int	game_is_wall(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		return (1);
	return (0);
}

static void	game_move_player(t_game *game, int dy, int dx)
{
	int	new_y;
	int	new_x;

	new_y = game->player_y + dy;
	new_x = game->player_x + dx;
	if (game_is_wall(game, new_y, new_x))
		return ;
	game->player_y = new_y;
	game->player_x = new_x;
	game_check_tile(game, new_y, new_x);
	game->move_count += 1;
	game_render_map(game);
}

int	game_handle_move_key(int key, t_game *game)
{
	if (key == 119 || key == 65362)
		game_move_player(game, -1, 0);
	else if (key == 115 || key == 65364)
		game_move_player(game, 1, 0);
	else if (key == 97 || key == 65361)
		game_move_player(game, 0, -1);
	else if (key == 100 || key == 65363)
		game_move_player(game, 0, 1);
	else
		return (0);
	return (1);
}
