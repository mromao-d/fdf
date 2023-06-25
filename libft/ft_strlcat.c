/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:08:00 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/28 18:17:19 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_l;

	size_l = size;
	if (size == 0)
		size = ft_strlen(src);
	else if (size <= ft_strlen(dst))
		size += ft_strlen(src);
	else
		size = ft_strlen(src) + ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	while (i + 1 < size_l && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i++] = '\0';
	return (size);
}
