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


int	main(void)
{
	t_game game;
	int x = 500;
	int y = 500;

	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	game.win = mlx_new_window(game.mlx, x, y, "mlx test");
	if (!game.win)
		return (1);
	if (!(game.assets.player.img = mlx_xpm_file_to_image(game.mlx, "open24.xpm", 
		&game.assets.player.width, &game.assets.player.height)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
	mlx_put_image_to_window(game.mlx,game.win,game.assets.player.img,0,0);
	mlx_hook(game.win, 2, 1L<<0, key_close_esc, &game);
	mlx_hook(game.win, 17, 0, key_close_x, &game);
	mlx_loop(game.mlx);
	
	return (0);
}
