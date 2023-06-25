/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:31:43 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/04 17:31:41 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
/* 
int main(void)
{
    printf("1 - The real result is: %d and the custom formula value is %d\n", 
        memcmp("\200", "\0", 1), ft_memcmp("\200", "\0", 1));

    printf("2 - The real result is: %d and the custom formula value is %d\n", 
        memcmp("\200", "\0", 5), ft_memcmp("\200", "\0", 5));
    
    printf("3 - The real result is: %d and the custom formula value is %d\n", 
        memcmp("asdasd", "asdash", 1), ft_memcmp("asdasd", "asdash", 1));
    
    printf("4 - The real result is: %d and the custom formula value is %d\n", 
        memcmp("asdasd", "asdash", 10), ft_memcmp("asdasd", "asdash", 10));


    return (0);
} */