/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:59:24 by adunal            #+#    #+#             */
/*   Updated: 2022/12/20 09:01:29 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_data(va_list *args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 's')
		return (ft_print_str(va_arg((*args), char *)));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long long), 1));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_u_int(va_arg((*args), unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex_nbr(va_arg((*args), unsigned int), c));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		res;

	res = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			res += ft_print_data(&args, str[i + 1]);
			i++;
		}
		else
			res += write(1, &str[i], 1);
		i++;
	}
	return (res);
}
/*
int main()
{
	ft_printf("%s", "adem");
}*/