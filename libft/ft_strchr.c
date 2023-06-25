/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:45:56 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/30 16:34:41 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	while (*s && chr != *s)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}
/* 
int	main(void)
{
    printf("%s\n", strchr("asdzasdsszzggrd", '\0'));
    printf("%s\n", ft_strchr("asdzasdsszzggrd", '\0'));
    return (0);
}
 */