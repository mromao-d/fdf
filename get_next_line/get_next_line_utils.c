/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:42:35 by mromao-d          #+#    #+#             */
/*   Updated: 2023/09/25 14:50:49 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*ft_strdup_(char	*str)
{
	char	*tmp;
	int		i;

	if (str && str == NULL)
		return (0);
	tmp = malloc(sizeof(char) * ft_strlen_(str) + 1);
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

int	ft_strlen_(char	*str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}
