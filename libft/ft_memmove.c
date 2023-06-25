/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:11:56 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/04 15:55:01 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (src <= dest)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dest);
}
/* 
int main(void)
{
	char s1[] = "aaaaaaaaaaaaa";
	char s11[] = "aaaaaaaaaaaaa";
 	char s2[] = "bbbbbbbbbbbbbbbbbbb";
	char s21[] = "bbbbbbbbbbbbbbbbbbb";
	int i = 8;

	printf("The real result is: %s\n", s1);
	printf("My result 	is: %s\n", s11);
	memmove(s1, s2, i);
	ft_memmove(s11, s21, i);
	printf("The real result is: %s\n", s1);
	printf("My result 	is: %s\n", s11);
	return (0);
} */