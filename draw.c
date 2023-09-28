
#include "headers/fdf.h"
#include ".minilibx-linux/mlx.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return b;
	return a;
}

float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void ft_bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int) (x - x1) || (int) (y - y1))
	{
		// mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xfffffff);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x += x_step;
		y += y_step;
	}
}
