/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/06/25 16:13:02 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*ft_strdup1(char	*str)
{
	char	*tmp;
	int		i;

	if (str && str == NULL)
		return (0);
	tmp = malloc(sizeof(char) * ft_strlen1(str) + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = 0;
	return (tmp);
}

int	ft_strlen1(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}
