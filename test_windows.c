#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 32

typedef struct s_img
{
	void	*img;
	int 	height;
	int		width;
}			t_img;

typedef struct s_assets
{
	t_img	player;
	t_img	wall;
	t_img	space;
	t_img	collect;
	t_img	exit;
	t_img	enemy;
}			t_assets;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	t_assets	assets;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			collect_count;
}				t_game;

int	print_key(int key, void *p)
{
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


int	main(void)
{
	t_game	game;
	char	*test_map[] = {
		"111111",
		"1P0C01",
		"1000E1",
		"10M001",
		"111111",
		NULL
	};

	game.map = test_map;
	game.map_width = 6;
	game.map_height = 5;
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
	mlx_hook(game.win, 2, 1L << 0, key_close_esc, &game);
	mlx_hook(game.win, 17, 0, key_close_x, &game);
	mlx_loop(game.mlx);
	return (0);
}