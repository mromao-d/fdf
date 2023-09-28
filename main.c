/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:02:14 by mromao-d          #+#    #+#             */
/*   Updated: 2023/09/27 20:57:08 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/fdf.h"

int ft_deal_key(int *key, void *data)
{
    (void) data;
    ft_printf("%d", key);
    return (0);
}

void    ft_print_matrix(int **shit)
{
    int i;
    int j;

    i = 0;
    while (shit[i])
    {
        j = 0;
        while (shit[i][j])
        {
            ft_printf("%i", shit[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    fdf *data;

    (void) argc;
    // (void) argv;
    data = (fdf *)malloc(sizeof(fdf));
    if (!data)
        return (0);
    ft_read_file(argv[1], data);
    ft_print_matrix(data->z_matrix_int);
    return (0);
}
