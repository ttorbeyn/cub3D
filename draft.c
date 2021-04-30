
int             main(void)
{
	void    *mlx;
	void    *mlx_win;
	t_data  img;
	int		a;
	int		b;
	int i;
	//int x;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 2000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*x = 1000;
	a = 0;
	while (a < 500)
	{
		b = 1000;
		while (b < x)
		{
			my_mlx_pixel_put(&img, a, b, 0x00FF0000);
			b++;
		}
		a++;
		x--;
	}*/
	a = 0;
	b = 200;
	i = 0;
	while (i < 2000 && b < 1000 && a < 1000)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF0000);
		b++;
		a++;
		i++;
	}
	/*a = 800;
	b = 1000;
	i = 0;
	while (i < 2000 && b > 0 && a < 1500)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF7F7F);
		b--;
		a++;
		i++;
	}
	a = 1500;
	b = 300;
	i = 0;
	while (i < 2000 && b < 1000 && a < 2000)
	{
		my_mlx_line_put(1000, a, b, img, 0x00FF0000);
		b++;
		a++;
		i++;
	}*/

	a = 0;
	b = 500;
	while (a < 2000)
	{
		my_mlx_pixel_put(&img, a, b, 0x000000FF);
		a++;
	}
	init(img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, deal_key, (void *)0);
	mlx_loop(mlx);
}