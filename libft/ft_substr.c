/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:33:26 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/30 16:58:17 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;
	size_t	malloc_size;

	if (!s)
		return (NULL);
	i = 0;
	malloc_size = 0;
	while (i + start < ft_strlen(s) && (malloc_size < len))
	{
		i++;
		malloc_size++;
	}
	output = malloc(sizeof(char) * (malloc_size + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < malloc_size)
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = 0;
	return (output);
}
/* 
int	main(void)
{
	char const *s;

	s = "123456789";
	printf("%ld\n", ft_strlen(s));
	printf("%s, %s", s, ft_substr(s, 0, 1));
	return (0);
} */