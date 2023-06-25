/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:29:22 by mromao-d          #+#    #+#             */
/*   Updated: 2022/12/28 18:17:48 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int		i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	if (lst->next == NULL)
		i++;
	return (i);
}
