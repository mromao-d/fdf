/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:38:31 by mromao-d          #+#    #+#             */
/*   Updated: 2023/01/03 13:31:09 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (NULL);
	output = malloc(sizeof(char *) * (char_count(s, c) + 1));
	if (!output)
		return (NULL);
	output [char_count(s, c)] = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (s[count] != c && s[count])
			count++;
		if (*s)
			output[i] = ft_substr(s, 0, count);
		i++;
		s = s + count;
		count = 0;
	}
	return (output);
}
/* 
int	main(void)
{
	char	*s;
	char	**output;
	char	c;
	int		i;

	i = 0;
	c = 'n';
	s = "My name is Manuel";
	output = ft_split(s, c);
	printf("%ld\n", first_char(s, c));
	printf("%s\n", ft_substr(s, 0, first_char(s, c)));
	while (i <= 9)
	{
		printf("string %d : %s\n", i, output[i]);
		i++;
	}
	return (0);
} */