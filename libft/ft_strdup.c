/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:26:54 by mromao-d          #+#    #+#             */
/*   Updated: 2023/01/03 12:31:37 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	char	*temp;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	temp = (char *) s;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!(new))
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = temp[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
