#ifndef FDF_H
# define FDF_H

#include "ft_printf.h"
#include "../libft/libft.h"
#include "get_next_line.h"
#include "../.minilibx-linux/mlx.h"

typedef struct
{
    int     width;
    int     height;
    int     **z_matrix_int;
    char    **z_matrix_char;

    void    *mlx_ptr;
    void    *win_ptr;
}   fdf;

int	ft_get_height(char *file_name);
int	ft_word_count(char *line, char skip);
int	ft_get_width(char *file_name);
void	ft_fill_matrix(int *z_line, char *line);
void	ft_read_file(char *file_name, fdf *data);
void ft_bresenham(float x, float y, float x1, float y1, fdf *data);

#endif
