/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:39:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/06/25 16:46:55 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

/* https://www.youtube.com/watch?v=10P59aOgi68 */

void	ft_read_map(int fd)
{
	char	**splited;

	fd = open("basictest.txt", O_RDONLY);
}

/* int main(void)
{
	int		fd;
	char	*s;

	fd = open("basictest.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	while (s && s != NULL)
	{
		s = get_next_line(fd);
		if (s != NULL)
			printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
} */
