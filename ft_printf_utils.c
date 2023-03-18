/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:25:04 by adunal            #+#    #+#             */
/*   Updated: 2022/12/20 09:02:01 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_int(int number)
{
	int	res;

	res = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		res += write(1, "-", 1);
		number *= -1;
	}
	if (number > 9)
		res += ft_int(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	return (res + 1);
}

int	ft_u_int(unsigned int number)
{
	int	res;

	res = 0;
	if (number > 9)
		res += ft_u_int(number / 10);
	write(1, &"0123456789"[number % 10], 1);
	return (res + 1);
}

int	ft_hex_nbr(unsigned int number, char c)
{
	int	res;

	res = 0;
	if (number > 15)
		res += ft_hex_nbr((number / 16), c);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[number % 16], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[number % 16], 1);
	return (res + 1);
}

int	ft_point(unsigned long long a, int sign)
{
	int	res;

	res = 0;
	if (sign == 1)
	{
		res = write(1, "0x", 2);
		sign = 0;
	}
	if (a > 15)
		res += ft_point((a / 16), 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (res + 1);
}
