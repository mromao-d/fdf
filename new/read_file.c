/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:39:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/10/15 15:06:14 by mromao-d         ###   ########.fr       */
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

static int	ft_char_count(char const *s, char c)
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
	int		w;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	w = ft_char_count(line, ' ');
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
		i++;
	}
	z_line[i] = 0;
	free(nums);
}

void	ft_read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = ft_get_height(file_name);
	data->width = ft_get_width(file_name);
	data->z_matrix_int = (int **)ft_calloc(sizeof(int *), (data->height + 1));
	if (!(data->z_matrix_int))
		return ;
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix_int[i] = (int *)ft_calloc(sizeof(int), (data->width
					+ 1));
		if (!(data->z_matrix_int[i]))
			return ;
		line = get_next_line(fd);
		ft_fill_matrix(data->z_matrix_int[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix_int[i] = NULL;
	return ;
}
