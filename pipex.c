/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:07:57 by aandric           #+#    #+#             */
/*   Updated: 2022/06/20 16:34:52 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	init_struct(t_cmd **cmd, char **args, int ac)
{
	int		i;
	t_cmd	*current;

	i = 2;
	if (ac < 5)
	{
		write(2, "Less than 5 parameters\n", 24);
		return (0);
	}
	while (i < ac - 1)
	{
		current = ft_lstnew_cmd(0);
		current->cmd = ft_strdup(args[i]);
		ft_lstadd_back_cmd(cmd, current);
		i++;
	}
	return (1);
}

void	free_struct(t_cmd *cmd)
{
	int		i;
	t_cmd	*struct_to_free;

	while (cmd)
	{
		i = 0;
		struct_to_free = cmd;
		free(cmd->full_path);
		while (cmd->envp && cmd->envp[i])
		{
			free(cmd->envp[i]);
			i++;
		}
		free(cmd->envp);
		i = 0;
		while (cmd->args && cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
		free(cmd->cmd);
		cmd = cmd->next;
		free(struct_to_free);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;

	cmd = NULL;
	if (!init_struct(&cmd, av, ac))
	{
		free_struct(cmd);
		return (0);
	}
	parse(cmd, av, envp, ac);
	exec_cmd(cmd);
	free_struct(cmd);
}
