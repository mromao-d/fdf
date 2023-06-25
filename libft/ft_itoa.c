/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:17 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/30 18:26:44 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nmbr(long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*result;

	nb = n;
	i = count_nmbr(nb) + 1;
	if (nb < 0)
		i += 1;
	if (nb == 0)
		return (ft_strdup("0"));
	result = (void *) ft_calloc(1, i);
	if (!(result))
		return (NULL);
	result [--i] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		result[--i] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (result);
}

/* int main (void)
{
	printf("%s\n", ft_itoa(0));
	return (0);
} */