/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:22:52 by aandric           #+#    #+#             */
/*   Updated: 2021/11/22 20:29:46 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_print_hexa_maj(unsigned int nbr, int fd);
int	ft_print_hexa_min(unsigned long nbr, int fd);
int	ft_print_memory(void *adress);
int	ft_printf(const char *type, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd_u(unsigned int n, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);

#endif