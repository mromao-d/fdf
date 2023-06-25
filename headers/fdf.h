#ifndef FDF_H
# define FDF_H

#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"

typedef struct
{
    int width;
    int height;
    int **z_matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}   fdf;


#endif
