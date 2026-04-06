/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_print_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:29:40 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/04/06 12:36:56 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char *move_count_str(int move_count)
{
	char *str;
	char *move_str;

	move_str = ft_itoa(move_count);
	str = ft_strjoin("Moves: ", move_str);
	free(move_str);
	return (str);
}

void game_print_move(t_game *game)
{
	char	*moves;

	moves = move_count_str(game->move_count);
    mlx_string_put(game->mlx, game->win, (game->map_width - 2)*TILE_SIZE,
        (game->map_height)*TILE_SIZE - 10, 0xFF99FF, moves);
	free(moves);
}