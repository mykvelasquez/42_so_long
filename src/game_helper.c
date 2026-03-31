/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:09:04 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 13:43:18 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_cleanup(t_game *game)
{
	if (game->assets.player.img)
		mlx_destroy_image(game->mlx, game->assets.player.img);
	if (game->assets.wall.img)
		mlx_destroy_image(game->mlx, game->assets.wall.img);
	if (game->assets.space.img)
		mlx_destroy_image(game->mlx, game->assets.space.img);
	if (game->assets.exit.img)
		mlx_destroy_image(game->mlx, game->assets.exit.img);
	if (game->assets.collect.img)
		mlx_destroy_image(game->mlx,game->assets.collect.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}