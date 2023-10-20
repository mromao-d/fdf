/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:02:14 by mromao-d          #+#    #+#             */
/*   Updated: 2023/10/20 18:46:40 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

void	ft_free_matrix(t_fdf *data)
{
	int	line;

	line = 0;
	while (line <= data->height)
	{
		free(data->z_matrix_int[line]);
		line++;
	}
	free(data->z_matrix_int);
}

int	ft_close_window(t_fdf *data)
{
	ft_free_matrix(data);
	if (!data->win_ptr || !data->win_ptr)
	{
		free(data);
		exit(0);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}

int	ft_press_cross(t_fdf *data)
{
	int	line;

	line = 0;
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	while (line <= data->height)
	{
		free(data->z_matrix_int[line]);
		line++;
	}
	free(data->z_matrix_int);
	free(data);
	exit(0);
}

void	shit_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_deal_key(int key, t_fdf *fdf, t_data img)
{
	ft_printf("%d\n", key);
	if (key == 65363)
		fdf->shift_x += 10;
	if (key == 65361)
		fdf->shift_x -= 10;
	if (key == 65364)
		fdf->shift_y += 10;
	if (key == 65362)
		fdf->shift_y -= 10;
	if (key == 65307)
		ft_close_window(fdf);
	// else
	// 	return (0);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_draw(fdf, img);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img.img, 0, 0);
	return (0);
}

unsigned char	ft_get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

int intToColor(int number) 
{
	if (number == 0)
		return (0x00FFFFFF);
    // Ensure the number is within a certain range (for example, 0 to 255)
    number = number % 256;

    // Assign the number to one of the RGB components
    int red = number;
    int green = (number + 85) % 256;  // Offset green by 85
    int blue = (number + 170) % 256; // Offset blue by 170

    // Combine the components into a single integer color code
    int colorCode = (red << 16) | (green << 8) | blue;

    return colorCode;
}

void perspectiveProjection(float x, float y, float z, float* outX, float* outY) 
{
    float depth = 200.0; // Adjust this value based on your scene
    *outX = (x * depth) / (depth + z);
    *outY = (y * depth) / (depth + z);
}

// int	main(int argc, char **argv)
// {
// 	t_data	img;
// 	t_fdf	*fdf;
// 	float	x;
// 	float	y;

// 	ft_check_file(argv[1], argc);
// 	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
// 	if (!fdf)
// 		return (0);
// 	ft_read_file(argv[1], fdf);
// 	fdf->mlx_ptr = mlx_init();
// 	if (!fdf->mlx_ptr)
// 	{
// 		ft_close_window(fdf);
// 		exit(0);
// 	}
// 	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf");
// 	if (!fdf->win_ptr)
// 	{
// 		ft_close_window(fdf);
// 		exit(0);
// 	}
// 	img.img = mlx_new_image(fdf->mlx_ptr, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	// int i = -1;
// 	// while (++i < 1000)
// 	// 	shit_pixel_put(&img, i, i, 0x00FF0000);
// 	ft_printf("%i", ft_get_g(fdf->z_matrix_int[10][10]));
// 	fdf->zoom = 20;
// 	// put all rows
// 	y = 0;
// 	while (y < fdf->height)
// 	{
// 		x = 0;
// 		while (x < fdf->width)
// 		{
// 			fdf->x = x - 0.99;
// 			while(fdf->x < x && fdf->x >= 0)
// 			{
// 				if (fdf->z_matrix_int[(int)y][(int)x] > 0)
// 					shit_pixel_put(&img, (fdf->x) * 20, y*fdf->zoom, intToColor(fdf->z_matrix_int[(int)y][(int)x]));
// 				else
// 					shit_pixel_put(&img, (fdf->x) * 20, y*fdf->zoom, intToColor(fdf->z_matrix_int[(int)y][(int)x]));
// 				// shit_pixel_put(&img, (fdf->x1) * 20, y*20, intToColor(fdf->z_matrix_int[y][x])/* 0x00FF0000 *//* (int)fdf->z_matrix_int[x][y] */);
// 				fdf->x += 0.01;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	// put all columns
// 	x = 0;
// 	while (x < fdf->width)
// 	{
// 		y = 0;
// 		while (y < fdf->height)
// 		{
// 			fdf->y = y - 0.99;
// 			// ft_isometric(&x, &y, fdf->z);
// 			// ft_isometric(&(fdf->x1), &(fdf->y1), fdf->z1);
// 			perspectiveProjection(fdf->x, fdf->y, fdf->z, &(fdf->x), &(fdf->y));
// 			while(fdf->y < y && fdf->y >= 0)
// 			{
// 				if (fdf->z_matrix_int[(int)y][(int)x] > 0)
// 					shit_pixel_put(&img, x * fdf->zoom, (fdf->y)*fdf->zoom, intToColor(fdf->z_matrix_int[(int)y][(int)x]));
// 				else
// 					shit_pixel_put(&img, x * fdf->zoom, (fdf->y)*fdf->zoom, intToColor(fdf->z_matrix_int[(int)y][(int)x]));
// 				// shit_pixel_put(&img, (fdf->x1) * 20, y*20, intToColor(fdf->z_matrix_int[y][x])/* 0x00FF0000 *//* (int)fdf->z_matrix_int[x][y] */);
// 				fdf->y += 0.01;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img.img, 0, 0);
// 	mlx_hook(fdf->win_ptr, 17, 1L << 17, ft_press_cross, fdf);
// 	mlx_hook(fdf->win_ptr, 2, 1L << 0, ft_deal_key, fdf);
// 	mlx_loop(fdf->mlx_ptr);
// }


// ft_isometric(&(data->x1), &(data->y1), data->z1);




int	main(int argc, char **argv)
{
	t_data	img;
	t_fdf	*fdf;

	ft_check_file(argv[1], argc);
	fdf = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (!fdf)
		return (0);
	ft_read_file(argv[1], fdf);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
	{
		ft_close_window(fdf);
		exit(0);
	}
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf");
	if (!fdf->win_ptr)
	{
		ft_close_window(fdf);
		exit(0);
	}
	img.img = mlx_new_image(fdf->mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	fdf->zoom = 30;
	ft_draw(fdf, img);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img.img, 0, 0);
	mlx_hook(fdf->win_ptr, 17, 1L << 17, ft_press_cross, fdf);
	mlx_hook(fdf->win_ptr, 2, 1L << 0, ft_deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}




