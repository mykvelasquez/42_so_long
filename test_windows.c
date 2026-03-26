#include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img;
	char 	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_img;

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_square_put(t_img *img, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_img	img;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 500, 500, "mlx test");
	if (!win)
		return (1);
	img.img = mlx_new_image(mlx,500,500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.size_line, &img.endian);
	my_mlx_square_put(&img, 50, 50);
	mlx_put_image_to_window(mlx, win, img.img, 100, 0);
	mlx_loop(mlx);
	
	return (0);
}
