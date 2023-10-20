/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:08:57 by mromao-d          #+#    #+#             */
/*   Updated: 2023/10/20 15:30:07 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

void	ft_check_fdf(char *file_name)
{
	int	i;

	i = -1;
	while (file_name[++i])
		;
	if (file_name[i - 4] != '.' || file_name[i - 3] != 'f' || \
		file_name[i - 2] != 'd' || file_name[i - 1] != 'f')
		exit(10);
}

void	ft_check_file(char *file_name, int argc)
{
	int	fd;

	if (argc != 2)
		exit(2);
	fd = open(file_name, O_RDONLY);
	if (fd != 3)
		exit(11);
	close(fd);
	return ;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_my_put_pixel(float x, float y, t_fdf *data, t_data *img)
{
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		my_mlx_pixel_put(img, \
		x + 300, y + 200, data->color);
		x += data->x_step;
		y += data->y_step;
	}
	return ;
}

void	ft_put_pixel(float x, float y, t_fdf *data)
{
	while ((int)(x - data->x1) || (int)(y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		x + 300, y + 200, data->color);
		x += data->x_step;
		y += data->y_step;
	}
	return ;
}

void	ft_bresenham_aux(t_fdf *data, float x, float y, int aux)
{
	if (aux == 0)
	{
		data->x1 = x + 1;
		data->y1 = y;
	}
	else
	{
		data->x1 = x;
		data->y1 = y + 1;
	}
}
