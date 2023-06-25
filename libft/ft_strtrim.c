/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:07 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/30 18:02:35 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	if (set[0] == '\0')
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i == j)
		return (ft_strdup("\0"));
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	output = ft_substr(s1, i, j - i + 1);
	return (output);
}
/* 
int main(void)
{
	char const *s1;
	char const *set;

	s1 = "   xxx   xxx";
	set = "x ";
	printf(" %s\n", ft_strtrim(s1, set));
	return (0);
} */