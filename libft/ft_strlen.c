/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:36:04 by mromao-d          #+#    #+#             */
/*   Updated: 2022/11/20 11:33:25 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/* 
int main (void)
{
// The original function consideres the output a unsigned long (lu) \
// and mine doesn't (d). Validate
    printf("%lu\n", strlen("asdsad"));
    printf("%d\n", ft_strlen("asdsad"));
    return (0);
} 
*/
