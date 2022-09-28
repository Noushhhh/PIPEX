/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:18:52 by aandric           #+#    #+#             */
/*   Updated: 2021/11/22 20:29:35 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_params(unsigned long nbr)
{
	int		i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 15)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	ft_print_hexa_min(unsigned long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 15)
		ft_print_hexa_min(nbr / 16, fd);
	ft_putchar_fd("0123456789abcdef"[nbr % 16], fd);
	return (ft_count_params(nbr));
}
