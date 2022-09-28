/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:20:22 by aandric           #+#    #+#             */
/*   Updated: 2022/04/07 14:20:03 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_type(const char c, va_list arg)
{	
	if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	if (c == 'p')
		return (ft_print_memory(va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	if (c == 'u')
		return (ft_putnbr_fd_u(va_arg(arg, unsigned long), 1));
	if (c == 'x')
		return (ft_print_hexa_min(va_arg(arg, unsigned int), 1));
	if (c == 'X')
		return (ft_print_hexa_maj(va_arg(arg, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *type, ...)
{
	int		i;
	int		arglen;
	va_list	arg;

	va_start(arg, type);
	i = 0;
	arglen = 0;
	while (type[i])
	{
		if (type[i] == '%')
		{
			arglen = arglen + ft_print_type(type[i + 1], arg);
			i = i + 2 ;
		}
		else
		{
			write(1, &type[i], 1);
			i++;
			arglen += 1;
		}
	}
	va_end(arg);
	return (arglen);
}

/*
#include <stdio.h>
int main ()
{
	char	*str;
	int	i;
	int j;

	j = 999;
	i = -52354654;
	str = 0;
	ft_printf("\n%d\n", (ft_printf("Hello %s %u %x %p kikoo%", str, i, j, &i)));
	printf("\n%d\n", (printf("Hello %s %u %x %p kikoo", str, i, j, &i)));
}
*/
