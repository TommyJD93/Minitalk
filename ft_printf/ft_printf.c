/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:35 by tterribi          #+#    #+#             */
/*   Updated: 2022/02/09 13:27:04 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list param)
{
	char	buffer;

	buffer = va_arg(param, int);
	ft_putchar_void(buffer);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	num_len(int num)
{
	int	cont;

	cont = 0;
	while (num != 0)
	{
		num = num / 10;
		cont++;
	}
	return (cont);
}

int	flags(const char c, va_list param)
{
	if (c == 'c')
		return (print_char(param));
	else if (c == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(param, unsigned long long)));
	else if (c == 'd')
		return (ft_printnbr(va_arg(param, int)));
	else if (c == 'i')
		return (ft_printnbr(va_arg(param, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(param, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(param, unsigned int), c));
	else if (c == '%')
		return (ft_putchar_int('%'));
	else
		return (0);
}

int	ft_printf(const char *a, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, a);
	i = 0;
	count = 0;
	while (a[i])
	{
		if (a[i] == '%')
		{
			count += flags(a[++i], params);
			i++;
			continue ;
		}
		else
			count++;
		ft_putchar_void(a[i]);
		i++;
	}
	return (count);
}
