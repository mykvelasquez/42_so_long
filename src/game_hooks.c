/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:29:40 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 13:29:47 by mvelasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_key(int key, void *p)
{
	(void)p;
	return (printf("Key %c : %d\n",key, key));
}

int	key_close_esc(int key, void *p)
{
	t_game *game;

	game = (t_game *)p;
	printf("key : %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	return (0);
}

int key_close_x(void *p)
{
	t_game *game;
	game = (t_game *)p;

	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return 0;
}