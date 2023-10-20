/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:38:47 by mromao-d          #+#    #+#             */
/*   Updated: 2023/10/20 18:46:41 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(01) - z;
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

// void	shit_my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	shit_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_bresenham(float x, float y, int aux, t_fdf *fdf, t_data img)
{
	int	tmpx;
	int	tmpy;

	tmpx = x;
	tmpy = y;
	// ft_bresenham_aux(fdf, x, y, aux);
	if (aux == 0)
	{
		fdf->x1 = x + 1;
		fdf->y1 = y;
	}
	else
	{
		fdf->x1 = x;
		fdf->y1 = y + 1;
	}
	fdf->z = fdf->z_matrix_int[(int)y][(int)x];
	fdf->z1 = fdf->z_matrix_int[(int)fdf->y1][(int)fdf->x1];
	x *= fdf->zoom;
	fdf->x1 *= fdf->zoom;
	y *= fdf->zoom;
	fdf->y1 *= fdf->zoom;
	if (fdf->z || fdf->z1)
		fdf->color = 0xe80c0c/* data->z */;
	else
		fdf->color = 0xffffff;
	ft_isometric(&x, &y, fdf->z);
	ft_isometric(&(fdf->x1), &(fdf->y1), fdf->z1);
	x += fdf->shift_x;
	y += fdf->shift_y;
	fdf->x1 += fdf->shift_x;
	fdf->y1 += fdf->shift_y;
	fdf->x_step = fdf->x1 - x;
	fdf->y_step = fdf->y1 - y;
	fdf->max = (int)ft_max(ft_abs(fdf->x_step), ft_abs(fdf->y_step));
	fdf->x_step /= fdf->max;
	fdf->y_step /= fdf->max;
	// shit_my_mlx_pixel_put(&img, x, y, fdf->z);
	shit_pixel_put(&img, x, y, fdf->color);
	// ft_put_pixel(x, y, data);
	// ft_put_pixel(x, y, data, img);
}

void	ft_draw(t_fdf *data, t_data img)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(x, y, 0, data, img);
			if (y < data->height - 1)
				ft_bresenham(x, y, 1, data, img);
			x++;
		}
		y++;
	}
}
