/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adunal <adunal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:25:10 by adunal            #+#    #+#             */
/*   Updated: 2022/12/20 08:56:04 by adunal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_print_data(va_list *args, const char c);
int		ft_printf(const char *str, ...);
int		ft_print_str(char *str);
int		ft_point(unsigned long long a, int sign);
int		ft_int(int a);
int		ft_u_int(unsigned int a);
int		ft_hex_nbr(unsigned int a, char c);

#endif