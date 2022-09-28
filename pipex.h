/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:58:52 by aandric           #+#    #+#             */
/*   Updated: 2022/06/20 15:21:03 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define PIPE_READ 0
# define PIPE_WRITE 1
# define STDERR 2
# define EXIT_FAILURE 1

typedef struct s_cmd
{
	int				fd_in;
	int				fd_out;
	char			*full_path;
	int				pipe[2];
	int				fd_here_pipe[2];
	char			**envp;
	char			**args;
	int				args_count;
	pid_t			pid;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}			t_cmd;

int		parse(t_cmd *cmd, char **av, char **envp, int ac);
int		exec_cmd(t_cmd *cmd);
int		redir_here(t_cmd *cmd);

/*list functions*/

t_cmd	*ft_lstlast_cmd(t_cmd *lst);
void	ft_lstadd_back_cmd(t_cmd **cmd, t_cmd *cmd_new);
t_cmd	*ft_lstnew_cmd(int content);

#endif