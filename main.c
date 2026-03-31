/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelasqu <mvelasqu@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:02 by mvelasqu          #+#    #+#             */
/*   Updated: 2026/03/31 11:25:32 by mvelasqu         ###   ########.fr       */
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

	if (argc != 2)
		return (ft_putendl_fd("Usage: ./so_long <map.ber>", 2), 1);
	init_so_long(&map_info, &unit_info);
	if (create_map(&map_info, unit_info, argv) == -1)
		return (free_so_long(&map_info), 1);
	print_map(map_info.map_str_arr);
	ft_printf("\n");
	if (map_dup(&map_info) == -1)
		return (free_so_long(&map_info), 1);
	if (map_check_find_path(&map_info, &unit_info) == -1)
		return (-1);
	print_map(map_info.map_str_dup);
	game.map = map_info.map_str_dup;
	game.map_width = map_info.x;
	game.map_height = map_info.y;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx,
			game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE,
			"mlx test");
	if (!game.win)
		return (1);
	load_assets(&game);
	render_map(&game);
	printf("%d\n", mlx_hook(game.win, 2, 1L << 0, key_close_esc, &game));
	printf("%d\n", mlx_hook(game.win, 17, 0, key_close_x, &game));
	mlx_loop(game.mlx);
	free_so_long(&map_info);
	return (0);
}
