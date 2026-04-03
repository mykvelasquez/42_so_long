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

int	game_print_key(int key, void *p)
{
	(void)p;
	return (printf("Key %c : %d\n",key, key));
}

int	game_key_handler(int key, void *p)
{
	t_game *game;

	game = (t_game *)p;
	printf("key : %d\n", key);
	printf("Player position: (%d, %d)\n", game->player_x, game->player_y);
	if (key == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == 119 || key == 65362)
	{
		game->player_y -= 1;
		if(game->map[game->player_y][game->player_x] == '1')
			game->player_y += 1;
		if(game->map[game->player_y][game->player_x] == 'C')
		{
			game->collect_count -= 1;
			game->map[game->player_y][game->player_x] = '0';
		}
		if (game->map[game->player_y][game->player_x] == 'E' && game->collect_count == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
		if (game->map[game->player_y][game->player_x] == 'X')
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
	}
	if (key == 115 || key == 65364)
	{
		game->player_y += 1;
			if(game->map[game->player_y][game->player_x] == '1')
			game->player_y -= 1;
		if(game->map[game->player_y][game->player_x] == 'C')
		{
			game->collect_count -= 1;
			game->map[game->player_y][game->player_x] = '0';
		}
		if (game->map[game->player_y][game->player_x] == 'E' && game->collect_count == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
		if (game->map[game->player_y][game->player_x] == 'X')
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
	}
	if (key == 97 || key == 65361)
	{
		game->player_x -= 1;
		if(game->map[game->player_y][game->player_x] == '1')
			game->player_x += 1;
		if(game->map[game->player_y][game->player_x] == 'C')
		{
			game->collect_count -= 1;
			game->map[game->player_y][game->player_x] = '0';
		}
		if (game->map[game->player_y][game->player_x] == 'E' && game->collect_count == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
		if (game->map[game->player_y][game->player_x] == 'X')
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
	}
	if (key == 100 || key == 65363)
	{
		game->player_x += 1;
		if(game->map[game->player_y][game->player_x] == '1')
			game->player_x -= 1;
		if(game->map[game->player_y][game->player_x] == 'C')
		{
			game->collect_count -= 1;
			game->map[game->player_y][game->player_x] = '0';
		}
		if (game->map[game->player_y][game->player_x] == 'E' && game->collect_count == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
		if (game->map[game->player_y][game->player_x] == 'X')
		{
			mlx_destroy_window(game->mlx, game->win);
			exit (0);
		}
	}
	game->move_count += 1;

	game_render_map(game);
	
	return (0);
}

int game_key_close_x(void *p)
{
	t_game *game;
	game = (t_game *)p;

	game_exit(game);
	return 0;
}