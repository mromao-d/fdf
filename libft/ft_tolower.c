/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:43:36 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/30 18:17:50 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/* 
int main(void)
{
    int i;

    i = 0;
    while (i++ <= 200)
        printf("the tolower of the number %d\t is %d\t, %d\n", i\
	, tolower(i), ft_tolower(i));
    return (0);
} */
