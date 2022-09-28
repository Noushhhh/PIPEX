/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:19:58 by aandric           #+#    #+#             */
/*   Updated: 2021/11/22 20:28:15 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_count_params(unsigned int nbr)
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

int	ft_print_hexa_maj(unsigned int nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr > 15)
		ft_print_hexa_maj(nbr / 16, fd);
	ft_putchar_fd("0123456789ABCDEF"[nbr % 16], fd);
	return (ft_count_params(nbr));
}
