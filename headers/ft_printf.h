/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:44:31 by mromao-d          #+#    #+#             */
/*   Updated: 2023/06/25 15:54:15 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* static int	ft_putstr1(char *str);
static int	ft_putbase(long long i, char *b, int base);
static int	ft_put_p(unsigned long long n, char *b, int b_size, int frist_exec);
static int	ft_va_args(va_list args, const char fmt, int print_len); */
int			ft_printf(const char *str, ...);

#endif