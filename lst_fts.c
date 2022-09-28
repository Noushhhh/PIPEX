/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandric <aandric@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:50:58 by aandric           #+#    #+#             */
/*   Updated: 2022/06/08 15:00:08 by aandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*ft_lstlast_cmd(t_cmd *lst)
{
	int		i;

	i = 0;
	if (!lst)
		return (0);
	while (lst -> next)
	{
		lst = lst -> next;
		i++;
	}
	return (lst);
}

void	ft_lstadd_back_cmd(t_cmd **cmd, t_cmd *cmd_new)
{
	t_cmd	*last;

	last = NULL;
	if (cmd != NULL)
	{
		if (*cmd != NULL)
		{
			last = ft_lstlast_cmd(*cmd);
			last->next = cmd_new;
			cmd_new->prev = last;
		}
		else
			*cmd = cmd_new;
	}
}

t_cmd	*ft_lstnew_cmd(int content)
{
	t_cmd	*newlist;

	newlist = malloc(sizeof(t_cmd));
	if (!newlist)
		return (NULL);
	ft_memset(newlist, content, sizeof(t_cmd));
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}
