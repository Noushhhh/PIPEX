/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:34:38 by aandric           #+#    #+#             */
/*   Updated: 2022/06/20 15:30:52 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	set_fds(t_cmd *cmd)
{
	if (cmd->prev)
		dup2(cmd->prev->pipe[PIPE_READ], STDIN_FILENO);
	else
	{
		if (dup2(cmd->fd_in, STDIN_FILENO) == -1)
			return (0);
	}
	if (cmd->next)
		dup2(cmd->pipe[PIPE_WRITE], STDOUT_FILENO);
	else
	{
		if (dup2(cmd->fd_out, STDOUT_FILENO) == -1)
			return (0);
	}
	return (1);
}

static int	wait_cmds(t_cmd *cmd)
{
	while (cmd)
	{
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->next;
	}
	return (1);
}

static int	print_error(char *error_type)
{
	ft_putstr_fd(error_type, 2);
	perror("");
	exit(1);
}

int	exec_cmd(t_cmd *cmd)
{
	t_cmd	*first;

	first = cmd;
	while (cmd)
	{
		if (pipe(cmd->pipe) == -1)
			print_error("pipe");
		cmd->pid = fork ();
		if (cmd->pid == -1)
			print_error("fds");
		if (cmd->pid == 0)
		{
			if (!set_fds(cmd))
				return (0);
			close(cmd->pipe[PIPE_READ]);
			if (!execve(cmd->full_path, cmd->args, cmd->envp))
				exit(EXIT_FAILURE);
		}
		else
			close(cmd->pipe[PIPE_WRITE]);
		cmd = cmd->next;
	}
	wait_cmds(first);
	return (1);
}
