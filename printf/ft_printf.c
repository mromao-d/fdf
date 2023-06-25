/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:38:59 by mromao-d          #+#    #+#             */
/*   Updated: 2023/06/25 15:45:27 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr1(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putbase(long long n, char *b, int base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n / base > 0)
		count += ft_putbase(n / base, b, base);
	count += write(1, &b[n % base], 1);
	return (count);
}

static int	ft_put_p(unsigned long long n, char *b, int b_size, int frist_exec)
{
	int	c_count;

	c_count = 0;
	if (!n && frist_exec == 0)
		return (write(1, "(nil)", 5));
	if (frist_exec == 0)
		c_count += ft_putstr1("0x");
	if (n / b_size > 0)
		c_count += ft_put_p(n / b_size, b, b_size, 1);
	c_count += write(1, &b[n % b_size], 1);
	return (c_count);
}

/* validates the args, the value of the format ditacted by fmt and returns the 
print lenght p_len */
static int	ft_va_args(va_list args, const char fmt, int p_len)
{
	int	c;

	p_len = 0;
	if (fmt == '%')
		p_len += write(1, "%", 1);
	else if (fmt == 'c')
	{
		c = va_arg(args, int);
		p_len += write(1, &c, 1);
	}
	else if (fmt == 's')
		p_len += ft_putstr1(va_arg(args, char *));
	else if (fmt == 'd' || fmt == 'i')
		p_len += ft_putbase(va_arg(args, int), "0123456789", 10);
	else if (fmt == 'x')
		p_len += ft_putbase(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (fmt == 'X')
		p_len += ft_putbase(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (fmt == 'u')
		p_len += ft_putbase(va_arg(args, unsigned int), "0123456789", 10);
	else if (fmt == 'p')
		p_len += ft_put_p(va_arg(args, long int), "0123456789abcdef", 16,
				0);
	return (p_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	va_start(args, str);
	print_len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			print_len += ft_va_args(args, *str, 0);
		}
		else
			print_len += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (print_len);
}

/* int	main(void)
{
	ft_printf("my: %X\n", -10);
	printf("printf: %X", -10);
	return (0);
} */