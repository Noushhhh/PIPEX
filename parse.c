/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:47:22 by aandric           #+#    #+#             */
/*   Updated: 2022/06/20 15:25:43 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	parse_args(t_cmd *cmd)
{
	cmd->args = ft_split(cmd->cmd, ' ');
	return (1);
}

static int	parse_envp(t_cmd *cmd, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			cmd->envp = ft_split(&envp[i][5], ':');
			return (1);
		}
		i++;
	}
	return (0);
}

static int	cmd_exists(t_cmd *cmd, char **envp, char *cmd_name)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!access(cmd_name, R_OK | X_OK))
	{
		cmd->full_path = ft_strdup(cmd_name);
		return (1);
	}
	while (envp[i])
	{
		cmd->full_path = ft_strjoin("/", cmd_name);
		tmp = cmd->full_path;
		cmd->full_path = ft_strjoin(envp[i], cmd->full_path);
		free(tmp);
		if (!access(cmd->full_path, R_OK | X_OK))
			return (1);
		free(cmd->full_path);
		i++;
	}
	cmd->full_path = NULL;
	return (0);
}

static int	parse_files(t_cmd *cmd, char *infile, char *outfile)
{
	if (!cmd->prev)
	{
		cmd->fd_in = open(infile, O_RDONLY);
		if (cmd->fd_in < 0)
			return (0);
	}
	if (!cmd->next)
	{
		cmd->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (cmd->fd_out < 0)
			return (0);
	}
	return (1);
}

int	parse(t_cmd *cmd, char **av, char **envp, int ac)
{
	t_cmd	*cmd_first;

	cmd_first = cmd;
	while (cmd)
	{
		if (!parse_args(cmd))
			return (0);
		if (!parse_files(cmd, av[1], av[ac - 1]))
			perror("fds");
		if (!parse_envp(cmd, envp))
			ft_putstr_fd("pipex: path not found\n", 2);
		if (!cmd_exists(cmd, cmd->envp, cmd->args[0]))
		{
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putstr_fd(cmd->cmd, 2);
			ft_putstr_fd("\n", 2);
		}
		cmd = cmd->next;
	}
	cmd = cmd_first;
	return (1);
}
