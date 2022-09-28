/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:18:40 by aandric           #+#    #+#             */
/*   Updated: 2022/04/22 13:23:54 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <limits.h>

/* get_next_line.c */

char	*get_next_line(int fd);
char	*get_line(char *line, char *buffer, int fd);

/* get_next_line_utils.c */

int		ft_strlen_gnl(char *s);
int		ft_chrn(char *s);
int		ft_len_to_malloc(char *s1, char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_save_rest(char *buffer, char *shifted_buffer);

#endif
