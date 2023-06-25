/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:55:17 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/04 14:06:20 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*output;
	int		keep_size;

	i = 0;
	keep_size = ft_strlen((char *)s2);
	output = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!(output))
		return (0);
	while (i < ft_strlen((char *)s1))
	{
		output[i] = s1[i];
		i++;
	}
	while ((i < ft_strlen((char *)s1) + keep_size && *s2))
	{
		output[i] = *s2++;
		i++;
	}
	output[i] = '\0';
	return (output);
}
/* 
int	main(void)
{
	printf("%s", ft_strjoin("My name is", "Manuel"));
	return (0);
} */