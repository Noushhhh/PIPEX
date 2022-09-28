/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:37:01 by aandric           #+#    #+#             */
/*   Updated: 2021/11/22 19:55:35 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_params(unsigned long nbr)
{
	int		i;

	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd_u(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (ft_count_params(n));
}
