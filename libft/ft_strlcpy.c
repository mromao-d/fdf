/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:58:21 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/28 18:17:12 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/* int	main(void)
{
    char dst[] = "dst";
    const char src[] = "srcasdasd";
    char dst1[] = "dst";
    const char src1[] = "srcasdasd";


    printf("The real result of strlcpy is: %lu dst value\
		is %s src value is %s\n", strlcpy(dst, src, 8), dst, src);

	printf("My real result of strlcpy is: %u dst value\
		is %s src value is %s\n", ft_strlcpy(dst1, src1, 8), dst1, src1);
    return (0);
} */