/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_with_numbers_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:39:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/09/27 19:49:04 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

/* https://www.youtube.com/watch?v=10P59aOgi68 */

int	ft_get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line != 0)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

static int	char_count(char const *s, char c)
{
	size_t	i;
	int		has;

	i = 0;
	has = 1;
	while (*s)
	{	
		if (*s == c)
			has = 1;
		if (*s != c && has == 1)
		{	
			has = 0;
			i++;
		}
		s++;
	}
	return (i);
}

int	ft_get_width(char *file_name)
{
	int	w;
	int	fd;
	char *line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	w = char_count(line, ' ');
	free(line);
	line = NULL;
	close(fd);
	return (w);
}

void	ft_fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		nums[i] = 0;
		i++;
	}
	free(nums);
}

void	ft_read_file(char *file_name, fdf *data)
{
	int		fd;
	int		i;

	
	data->height = ft_get_height(file_name);
	data->z_matrix_char = (char**)malloc(sizeof(char *) * (data->height + 1));
	if (!(data->z_matrix_char))
		return ;
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix_char[i++] = (char*)malloc(sizeof(char) * (data->width + 1));
		if (!(data->z_matrix_char[i-1]))
			return ;
	}
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < data->height)
	{

		data->z_matrix_char[i] = (char *)malloc(sizeof(char) * (data->width + 1));
		if (!(data->z_matrix_char[i]))
            return ;
		data->z_matrix_char[i] = get_next_line(fd);
		i++;
	}
	data->z_matrix_char[i] = NULL;
	close(fd);
	data->z_matrix_char[i] = NULL;
}
