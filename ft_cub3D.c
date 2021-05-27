#include "cub3D.h"

int set_data(t_data *img)
{
	img->px = 45;
	img->py = 35;
	img->angle = PI/2;
	img->cellsize = 10;
	img->height = 1000;
	img->width = 2000;
	img->map = ft_parsing();
	img->userheight = img->cellsize / 20;
	return (0);
}

int	make_image(t_data *img)
{
	draw_minimap(img);
	raycasting(img);
	big_pixel(img, 0x00FF0000, (img->px - (img->userheight / 2)),
			  (img->py + (img->userheight / 2)), img->userheight);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;
	set_data(&img);

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.width, img.height, "cub3D");
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	make_image(&img);
	mlx_hook(img.mlx_win, 2, 1L<<0, deal_key, &img);
	mlx_loop(img.mlx);
}