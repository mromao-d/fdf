/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:47:15 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/04 17:49:36 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len) && len > 0)
		{
			if (little[j + 1] == '\0')
			{	
				return (&((char *) big)[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/* 
int	main(void)
{
    const char *one = "My name is Manuel";
    const char *one1 = "My name is Manuel";
    const char *two = "e ";
    const char *two1 = "e ";

    printf("the real result is: %s\n my result is:\
	 %s\n", strnstr(one, two, 20), ft_strnstr(one1, two1, 20));
    return (0);
} */